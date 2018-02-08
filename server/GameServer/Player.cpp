﻿#include "stdfx.h"
#include "Player.h"
#include "scene.h"
#include "scenemgr.h"
#include <iostream>

CPlayer::CPlayer()
{

}

CPlayer::~CPlayer()
{
}

void CPlayer::Run()
{
	CBaseObj::Run();
}

// 加载数据
bool CPlayer::LoadData(Msg *pMsg)
{
	svrData::LoadPlayerData msg;
	_CHECK_PARSE_(pMsg, msg) false;

	SetName(msg.name().c_str());
	SetNowPos(msg.x(), msg.y(), msg.z());

	SetScene(CScenemgr::Instance().GetScene(msg.mapid()));
	GetScene()->AddObj(this);
	SetName("");


	log_error("加载玩家数据成功！%s", msg.account().c_str());

	return true;
}

// 保存数据
bool CPlayer::SaveData()
{
	return true;
}

// 下线
void CPlayer::OffLine()
{
	if(GetScene())
		GetScene()->DelObj(this);
}