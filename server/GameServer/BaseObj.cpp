﻿#include "baseobj.h"
#include "assert.h"
#include "scene.h"

#define AOI_RADIS 200.0f
#define AOI_RADIS2 (AOI_RADIS * AOI_RADIS)
#define LEAVE_AOI_RADIS2 AOI_RADIS2 * 4
#define DIST2(p1,p2) ((p1[EPP_X] - p2[EPP_X]) * (p1[EPP_X] - p2[EPP_X]) + (p1[EPP_Y] - p2[EPP_Y]) * (p1[EPP_Y] - p2[EPP_Y]) + (p1[EPP_Z] - p2[EPP_Z]) * (p1[EPP_Z] - p2[EPP_Z]))

CBaseObj::CBaseObj()
{
	m_NowMapID = 0;
	memset(m_NowPos, 0, sizeof(float) * EPP_MAX);
	m_TempID = 0;
	m_Scene = nullptr;
	m_ObjName.clear();
	m_AoiList.clear();
}

CBaseObj::~CBaseObj()
{
	m_NowMapID = 0;
	memset(m_NowPos, 0, sizeof(float) * EPP_MAX);
	m_TempID = 0;
	m_Scene = nullptr;
	m_ObjName.clear();
	m_AoiList.clear();
}

void CBaseObj::Run()
{
	AoiRun();
}

void CBaseObj::SetScene(CScene *_Scene)
{
	m_Scene = _Scene;
}

// 移动到某个坐标
bool CBaseObj::MoveTo(float &x, float &y, float &z)
{
	if (m_Scene->MoveTo(this, x, y, z))
	{
		SetNowPos(x, y, z);
		return true;
	}

	return false;
}

// 获取当前坐标
void CBaseObj::GetNowPos(float &x, float &y, float &z)
{
	x = m_NowPos[EPP_X];
	y = m_NowPos[EPP_Y];
	z = m_NowPos[EPP_Z];
}

// 设置当前坐标
void CBaseObj::SetNowPos(const float &x, const float &y, const float &z)
{
	m_NowPos[EPP_X] = x;
	m_NowPos[EPP_Y] = y;
	m_NowPos[EPP_Z] = z;
}

// 添加对象至AoiList
void CBaseObj::AddToAoiList(CBaseObj * p)
{
#ifdef _DEBUG
	assert(p);
	auto iter = m_AoiList.find(p->GetTempID());
	assert(iter == m_AoiList.end());
#endif
	m_AoiList[p->GetTempID()] = p;
}

// 从AoiList中移除对象
void CBaseObj::DelFromAoiList(uint32_t id)
{
#ifdef _DEBUG
	auto iter = m_AoiList.find(id);
	assert(iter != m_AoiList.end());
#endif
	m_AoiList.erase(id);
}

// 添加对象至AoiList
void CBaseObj::AddToAoiListOut(CBaseObj * p)
{
#ifdef _DEBUG
	assert(p);
	auto iter = m_AoiList.find(p->GetTempID());
	assert(iter == m_AoiList.end());
#endif
	m_AoiList[p->GetTempID()] = p;
}

// 从AoiList中移除对象
void CBaseObj::DelFromAoiListOut(uint32_t id)
{
#ifdef _DEBUG
	auto iter = m_AoiList.find(id);
	assert(iter != m_AoiList.end());
#endif
	m_AoiList.erase(id);
}

// AoiList清理
void CBaseObj::AoiRun()
{
	auto iterB = m_AoiList.begin();
	for (; iterB!= m_AoiList.end();)
	{
		CBaseObj* _Obj = iterB->second;
		if (_Obj)
		{
			float _Pos[EPP_MAX] = { 0 };
			_Obj->GetNowPos(_Pos[EPP_X], _Pos[EPP_Y], _Pos[EPP_Z]);
			float nDistance = DIST2(_Pos, m_NowPos);
			if (nDistance > AOI_RADIS2 && nDistance <= LEAVE_AOI_RADIS2)
			{
				// 离开视野，移动到m_AoiListOut
				iterB = m_AoiList.erase(iterB);
				AddToAoiListOut(_Obj);
				continue;
			}
			else if (nDistance > LEAVE_AOI_RADIS2)
			{
				// 需要移除
				iterB = m_AoiList.erase(iterB);
				continue;
			}
		}
		++iterB;
	}

	auto iterOutB = m_AoiListOut.begin();
	for (; iterOutB != m_AoiListOut.end();)
	{
		CBaseObj* _Obj = iterOutB->second;
		if (_Obj)
		{
			float _Pos[EPP_MAX] = { 0 };
			_Obj->GetNowPos(_Pos[EPP_X], _Pos[EPP_Y], _Pos[EPP_Z]);
			float nDistance = DIST2(_Pos, m_NowPos);
			if (nDistance <= AOI_RADIS2)
			{
				// 进入视野，移动到m_AoiList
				iterOutB = m_AoiListOut.erase(iterOutB);
				AddToAoiList(_Obj);
				continue;
			}
			else if (nDistance > LEAVE_AOI_RADIS2)
			{
				// 需要移除
				iterOutB = m_AoiListOut.erase(iterOutB);
				continue;
			}
		}
		++iterOutB;
	}
}