﻿/*
* Client连接管理器
* Copyright (C) ddl
* 2018
*/
#pragma once
#include "ClientMgr.h"

class CGateClientMgr : public CClientMgr
{
public:
	CGateClientMgr();
	~CGateClientMgr();

	static CGateClientMgr &Instance()
	{
		static CGateClientMgr m;
		return m;
	}

	int64 OnNewClient();
	void OnClientDisconnect(CClient *cl);
	void ProcessClientMsg(CClient *cl);

private:

};