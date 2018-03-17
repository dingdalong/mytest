﻿/*
* 名字检查服务器
* Copyright (C) ddl
* 2018
*/

#include "config.h"
#include "NameCheckServer.h"
#include "NetConfig.h"
#include "ServerLog.h"
#include "lxnet.h"

#pragma comment(lib,"fmt.lib") 

#ifdef _WIN32
#include <windows.h>
#include "MiniDump.h"

#define delaytime(v)	Sleep(v)
#else
#include <unistd.h>

#define delaytime(v)	usleep((v) * 1000)
#define system(a)
#endif

bool init()
{
#ifdef _WIN32
	if (!CMiniDump::Begin())
	{
		RunStateError("初始化MiniDump失败!");
		system("pause");
		return false;
	}
#endif

	if (!init_log("NameCheckServer_Log"))
	{
		RunStateError("初始化Log失败!");
		return false;
	}

	//读取网络配置文件
	if (!CNetConfig::Instance().Init())
	{
		RunStateError("初始化NetConfig失败!");
		system("pause");
		return 0;
	}

	//读取配置文件
	if (!CConfig::Instance().Init("NameCheckServer"))
	{
		RunStateError("初始化Config失败!");
		system("pause");
		return 0;
	}

	g_elapsed_log_flag = CConfig::Instance().IsOpenElapsedLog();

	RunStateLog("名称检查服务器开始启动!");

	//初始化网络库
	if (!lxnet::net_init(CNetConfig::Instance().GetBigBufSize(), CNetConfig::Instance().GetBigBufNum(),
		CNetConfig::Instance().GetSmallBufSize(), CNetConfig::Instance().GetSmallBufNum(),
		CNetConfig::Instance().GetListenerNum(), CNetConfig::Instance().GetSocketerNum(),
		CNetConfig::Instance().GetThreadNum()))
	{
		RunStateError("初始化网络库失败!");
		system("pause");
		return 0;
	}
	//设置监听端口，创建listener
	if (!CCheckNameServer::Instance().Init())
	{
		RunStateError("初始化失败!");
		system("pause");
		return 0;
	}

	CCheckNameServer::Instance().Run();
	//循环结束后的资源释放
	CCheckNameServer::Instance().Release();
	lxnet::net_release();
	release_log();
#ifdef _WIN32
	CMiniDump::End();
#endif
	return true;
}

int main(void)
{
	init();
	return 0;
}