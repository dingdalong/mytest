﻿/*
* 中心服务器连接
* Copyright (C) ddl
* 2018
*/
#pragma once
#include "ServerConnect.h"

class CDBCenterConnect : public CServerConnect
{
public:
	CDBCenterConnect();
	~CDBCenterConnect();

	static CDBCenterConnect &Instance()
	{
		static CDBCenterConnect m;
		return m;
	}

	bool Init();

	// 连接断开的处理
	void ConnectDisconnect();
	// 处理远程服务器发来的消息
	void ProcessMsg(connector *_con);
private:

};