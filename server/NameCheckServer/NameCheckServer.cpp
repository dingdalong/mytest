﻿#include "NameCheckServer.h"
#include "NameCheckServerMgr.h"
#include "config.h"
#include "Timer.h"
#include "ServerLog.h"
#include "crosslib.h"
#include "NameSet.h"

#ifdef _WIN32
#include <windows.h>
#include "CtrlHandler.h"

#define delaytime(v)	Sleep(v)
#else
#include <unistd.h>

#define delaytime(v)	usleep((v) * 1000)
#define system(a)
#endif

int64 g_currenttime;

CCheckNameServer::CCheckNameServer()
{
	m_Run = false;
}

CCheckNameServer::~CCheckNameServer()
{
	m_Run = false;
}

static void cb()
{
	CCheckNameServer::Instance().Destroy();
}

bool CCheckNameServer::Init()
{
	do
	{
#ifdef _WIN32
		if (!CCtrlHandler::Instance().Init(&cb))
		{
			RunStateError("初始化CtrlHandler失败!");
			break;
		}
#endif
		if (!CNameCheckServerMgr::Instance().Init(
			CConfig::Instance().GetServerIP(),
			CConfig::Instance().GetServerID(),
			CConfig::Instance().GetListenPort(),
			CConfig::Instance().GetOverTime()))
		{
			RunStateError("初始化 NameCheckServerMgr 失败!");
			break;
		}

		m_Run = true;
		return true;

	} while (true);

	CNameCheckServerMgr::Instance().Destroy();
	CNameSet::Instance().Destroy();

	Destroy();

	return false;
}

bool CCheckNameServer::Release()
{
	return true;
}

void CCheckNameServer::Run()
{
	const int normaldelay = 50;
	const int maxdelay = normaldelay * 2;
	int delay;
	while (m_Run)
	{
		CNameCheckServerMgr::Instance().ResetMsgNum();
		CTimer::UpdateTime();

		g_currenttime = get_millisecond();
		RunOnce();
		delay = (int)(get_millisecond() - g_currenttime);
		if (delay < normaldelay)
		{
			delaytime(normaldelay - delay);
		}
		else if (delay > maxdelay)
		{
			ElapsedLog("运行超时:%d\n%s", delay, CNameCheckServerMgr::Instance().GetMsgNumInfo());
		}
	}
	delaytime(300);

	CNameCheckServerMgr::Instance().Destroy();
	CNameSet::Instance().Destroy();

	Destroy();
}

void CCheckNameServer::Exit()
{
	m_Run = false;
}

void CCheckNameServer::RunOnce()
{
	lxnet::net_run();

	CNameCheckServerMgr::Instance().Run();

	CNameCheckServerMgr::Instance().EndRun();
}

void CCheckNameServer::Destroy()
{
	Exit();
}