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
		nClientID = 0;
		nLoginServerID = 0;
		nGateID = 0;
		nGameServerID = 0;
	}
	int64 nClientID;
	int nLoginServerID;
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

	void AddClientSvr(int32 clientid, int serverid, int servertype);
	void DelClientSvr(int32 id);
	ClientSvr *GetClientSvr(int32 id);
private:

	std::vector<ClientSvr *> m_ClientSvrSet;
};