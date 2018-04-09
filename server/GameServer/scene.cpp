﻿#include "platform_config.h"
#include "Scene.h"
#include "BaseObj.h"
#include "MapInfo.h"
#include "idmgr.c"
#include "serverlog.h"
#include "Utilities.h"

CScene::CScene()
{
	m_MapID = 0;
	m_Width = 0;
	m_Height = 0;
	m_BirthPoint_X = 0.0f;
	m_BirthPoint_Y = 0.0f;
	m_BirthPoint_Z = 0.0f;
	m_Barinfo = nullptr;
	m_Cookie = nullptr;
	m_Space = nullptr;
	m_bMessage = false;
	m_IDPool = nullptr;
	m_ObjMap.clear();
	m_ObjSet.clear();
}

CScene::~CScene()
{
	Destroy();
}

void CScene::Destroy()
{
	if (m_Space)
	{
		aoi_release(m_Space);
		m_Space = nullptr;
	}

	if (m_Cookie)
	{
		delete m_Cookie;
		m_Cookie = nullptr;
	}

	if (m_IDPool)
	{
		idmgr_release(m_IDPool);
		m_IDPool = nullptr;
	}

	m_ObjMap.clear();
	m_ObjSet.clear();
}

static void *my_alloc(void * ud, void *ptr, size_t sz) {
	struct alloc_cookie * cookie = (struct alloc_cookie *)ud;
	if (ptr == NULL) {
		void *p = nullptr;
		try {
			p = malloc(sz);
		}
		catch (std::bad_alloc &) {
			p = nullptr;
		}
		++cookie->count;
		cookie->current += sz;
		if (cookie->max < cookie->current) {
			cookie->max = cookie->current;
		}
		//		printf("%p + %u\n",p, sz);
		return p;
	}
	--cookie->count;
	cookie->current -= sz;
	//	printf("%p - %u \n",ptr, sz);
	free(ptr);
	return NULL;
}

bool CScene::Init(CMapInfo * _mapinfo)
{
	if (!_mapinfo)
		return false;
	
	m_MapID = _mapinfo->GetMapID();
	_mapinfo->GetMapBirthPoint(m_BirthPoint_X, m_BirthPoint_Y, m_BirthPoint_Z);
	_mapinfo->GetMapWidthAndHeight(m_Width, m_Height);

	if (m_MapID <= 0 || m_Width <= 0 || m_Height <= 0)
	{
		RunStateError("场景[%d]获取地图宽[%d]、高[%d]失败!", m_MapID, m_Width, m_Height);
		return false;
	}

	m_IDPool = idmgr_create(SCENE_ID_MAX + 1, CLIENT_ID_DELAY_TIME);
	if (!m_IDPool)
	{
		RunStateError("创建IDMgr失败!");
		return false;
	}

	alloc_cookie* cookie = nullptr;
	try {
		cookie = new alloc_cookie;
	}
	catch (std::bad_alloc &) {
		cookie = nullptr;
	}
	if (cookie)
	{
		memset(cookie, 0, sizeof(alloc_cookie));
		aoi_space * space = aoi_create(my_alloc, cookie);
		if (space)
		{
			m_Space = space;
			m_Cookie = cookie;
		}
		else
		{
			delete cookie;
			cookie = nullptr;
			idmgr_release(m_IDPool);
		}
	}
	else
		idmgr_release(m_IDPool);

	m_Barinfo = _mapinfo->GetBarInfo();	
	m_ObjSet.resize(SCENE_ID_MAX + 1, nullptr);
	return true;
}

bool CScene::AddObj(CBaseObj * obj)
{
	if (!FuncUti::isValidCret(obj))
		return false;
	
	CScene *OldScene = obj->GetScene();
	assert(!OldScene);
	if (OldScene)
	{
		if (!OldScene->DelObj(obj))
		{
			RunStateError("对象%d从原地图[%d]移除失败!", obj->GetTempID(), OldScene->GetMapID());
			return false;
		}
	}

	int32 id = idmgr_allocid(m_IDPool);
	if (id <= 0)
	{
		RunStateError("为新对象分配ID失败!, id:%d", id);
		return false;
	}
	obj->SetTempID(id);
	obj->SetScene(this);
	m_ObjMap[obj->GetTempID()] = obj;

	assert(m_ObjSet[id] == nullptr);
	m_ObjSet[id] = obj;
	obj->MoveTo(m_BirthPoint_X, m_BirthPoint_Y, m_BirthPoint_Z);
	Update(obj->GetTempID(), obj->GetAoiMode(), obj->GetNowPos());

	return true;
}

bool CScene::DelObj(CBaseObj * obj)
{
	if (!FuncUti::isValidCret(obj))
		return false;

	int32 id = obj->GetTempID();
	if (id <= 0 || id >= static_cast<int32> (m_ObjSet.size()))
	{
		RunStateError("要释放的CBaseObj的ID错误!");
		return false;
	}

	m_ObjSet[id] = nullptr;

	if (!idmgr_freeid(m_IDPool, obj->GetTempID()))
	{
		RunStateError("释放ID错误, ID:%d", id);
	}

	obj->LeaveAoi();
	obj->SetTempID(0);
	m_ObjMap.erase(obj->GetTempID());
	return true;
}

bool CScene::bCanMove(int32 x, int32 y, int32 z)
{
	if (x >= 0 && x < m_Width)
	{
		if (y >= 0 && y < m_Height)
		{
			if (m_Barinfo)
			{
				return !m_Barinfo[x * y];
			}
		}
	}
	return false;
}

bool CScene::MoveTo(CBaseObj * obj, float x, float y, float z)
{
	if (FuncUti::isValidCret(obj))
	{
		if (bCanMove(static_cast<int>(floor(x)), static_cast<int>(floor(y)), static_cast<int>(floor(z))))
		{
			obj->SetNowPos(x, y, z);
			Update(obj->GetTempID(), obj->GetAoiMode(), obj->GetNowPos());
			return true;
		}
	}

	return false;
}

static void callbackmessage(void *ud, uint32 watcher, uint32 marker) 
{
	CScene* sc = (CScene*)ud;
	if (sc)
	{
		CBaseObj * p1 = sc->GetObj(watcher);
		if (FuncUti::isValidCret(p1))
		{
			CBaseObj * p2 = sc->GetObj(marker);
			if (FuncUti::isValidCret(p2))
			{
				p1->AddToAoiList(p2);
				// 非玩家，需要帮忙加一下
				if (!p2->IsPlayer())
					p2->AddToAoiList(p1);
			}
		}
	}
}

void CScene::Message()
{
	aoi_message(m_Space, callbackmessage, this);
}

void CScene::Update(uint32 id, const char * mode,float pos[3])
{
	aoi_update(m_Space, id, mode, pos);
	m_bMessage = true;
}

void CScene::Run()
{
	if (m_bMessage)
	{
		Message();
		m_bMessage = false;
	}

}

CBaseObj * CScene::GetObj(int32 id)
{
	if (id <= 0 || id >= static_cast<int32> (m_ObjSet.size()))
		return nullptr;

	return m_ObjSet[id];
}