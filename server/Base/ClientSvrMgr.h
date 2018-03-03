﻿/*
* Client所在服务器管理
* Copyright (C) ddl
* 2018
*/
#pragma once

#include <list>
struct ClientSvr
{
	ClientSvr()
	{
		nGateID = 0;
		nGameServerID = 0;
	}
	int nGateID;
	int nGameServerID;
};

class CClientSvrMgr
{
public:
	CClientSvrMgr();
	~CClientSvrMgr();


	static CClientSvrMgr &Instance()
	{
		static CClientSvrMgr m;
		return m;
	}
	bool Init();
	void Destroy();

	void AddClientSvr(int32 clientid, int32 serverid, int32 gateid);
	void DelClientSvr(int32 clientid);
	ClientSvr *GetClientSvr(int32 id);
private:

	std::vector<ClientSvr *> m_ClientSvrSet;
};