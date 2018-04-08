﻿/*
* 基础对象
* Copyright (C) ddl
* 2018
*/

#pragma once
#include <unordered_map>
#include "GlobalDefine.h"
#include "platform_config.h"
#include "ObjScene.h"
#include "ObjAttribute.h"
#include "ObjStatus.h"
#include "ObjFight.h"

extern int player_delay_time;
extern int64 g_currenttime;

enum eObjType
{
	EOT_PLAYER = 0,
	EOT_MONSTER = 1,
	EOT_NPC = 2,
	EOT_MAX ,
};

class CBaseObj :public CObjScene, public CObjAttribute, public CObjStatus, public CObjFight
{
public:
	CBaseObj(int8 nObjType);
	~CBaseObj();

	virtual CBaseObj *GetObj() { return this; }
	virtual void Run();
	virtual void Die() {}
public:
	int8 GetObjType() { return m_ObjType; }
	void SetSex(int8 sex) { m_ObjSex = sex; }
	int8 GetSex() { return m_ObjSex; }
	void SetJob(int8 job) { m_ObjJob = job; }
	int8 GetJob() { return m_ObjJob; }
	void SetLevel(int8 level) { m_ObjLevel = level; }
	int8 GetLevel() { return m_ObjLevel; }
	bool IsPlayer() { return m_ObjType == EOT_PLAYER; }
	bool IsMonster() { return m_ObjType == EOT_MONSTER; }
	bool IsNPC() { return m_ObjType == EOT_NPC; }
	char *GetName() { return m_ObjName; }
	void SetName(const char *_Name) {
		strncpy_s(m_ObjName, _Name, MAX_NAME_LEN); m_ObjName
			[MAX_NAME_LEN - 1] = '\0';
	}
private:
	// 对象类型
	int8 m_ObjType;
	int8 m_ObjSex;
	int8 m_ObjJob;
	int8 m_ObjLevel;
	// 名称
	char m_ObjName[MAX_NAME_LEN];
public:
	void SetWaitRemove() { m_WaitRemoveTime = g_currenttime; }
	bool IsWaitRemove() { return m_WaitRemoveTime > 0; }
	bool CanRemove(int64 time) { return time >= m_WaitRemoveTime + player_delay_time; }

private:
	// 待移除时间
	int64 m_WaitRemoveTime;
};
