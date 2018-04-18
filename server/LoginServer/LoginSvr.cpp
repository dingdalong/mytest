﻿#include "crosslib.h"
#include "loginsvr.h"
#include "LoginClientMgr.h"
#include "LoginCenterConnect.h"
#include "config.h"
#include "Timer.h"
#include "ServerLog.h"
#include "ClientAuth.h"
#include "LogConnecter.h"
#include "BackCommand.h"
#include "objectpool.h"

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

CLoginServer::CLoginServer()
{
	m_BackCommand = nullptr;
	m_Run = false;
}

CLoginServer::~CLoginServer()
{
	m_BackCommand = nullptr;
	m_Run = false;
}

static void cb()
{
	CLoginServer::Instance().Destroy();
}

bool CLoginServer::Init()
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
		if (!InitBackCommand())
		{
			RunStateError("初始化 BackCommand 失败!");
			break;
		}

		if (!CLoginClientMgr::Instance().Init(CConfig::Instance().GetMaxClientNum(),
			CConfig::Instance().GetListenPort(),
			CConfig::Instance().GetOverTime(),
			CConfig::Instance().GetRecvDataLimt(),
			CConfig::Instance().GetSendDataLimt()))
		{
			RunStateError("初始化client mgr 失败!");
			break;
		}

		if (!CLoginCenterConnect::Instance().Init())
		{
			RunStateError("初始化中心服务器连接失败!");
			break;
		}

		if (!CLogConnecter::Instance().Init(
			CConfig::Instance().GetLogServerIP(),
			CConfig::Instance().GetLogServerPort(),
			CConfig::Instance().GetLogServerID(),
			CConfig::Instance().GetLogServerName(),
			CConfig::Instance().GetServerID(),
			CConfig::Instance().GetServerType(),
			CConfig::Instance().GetServerName(),
			CConfig::Instance().GetPingTime(),
			CConfig::Instance().GetOverTime()))
		{
			RunStateError("初始化 LogConnecter 失败!");
			break;
		}

		if (!CClientAuth::Instance().Init())
		{
			RunStateError("初始化 ClientAuth 失败!");
			break;
		}

		m_Run = true;
		return true;
	} while (true);

	CLoginClientMgr::Instance().Destroy();
	CLoginCenterConnect::Instance().Destroy();
	CLogConnecter::Instance().Destroy();
	CClientAuth::Instance().Destroy();
	Destroy();

	return false;
}

bool CLoginServer::Release()
{
	return true;
}

void CLoginServer::Run()
{
	const int normaldelay = 50;
	const int maxdelay = normaldelay * 2;
	int delay;
	while (m_Run)
	{
		CLoginCenterConnect::Instance().ResetMsgNum();
		CLogConnecter::Instance().ResetMsgNum();
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
			ElapsedLog("运行超时:%d", delay);
			ElapsedLog("中心服务器连接：%s", CLoginCenterConnect::Instance().GetMsgNumInfo());
			ElapsedLog("日志服务器连接：%s", CLogConnecter::Instance().GetMsgNumInfo());
		}
	}
	delaytime(300);

	CLoginCenterConnect::Instance().Destroy();
	CLogConnecter::Instance().Destroy();
	CLoginClientMgr::Instance().Destroy();
	CClientAuth::Instance().Destroy();

	Destroy();
}

void CLoginServer::Exit()
{
	m_Run = false;
}

void CLoginServer::RunOnce()
{
	lxnet::net_run();
	m_BackCommand->Run(g_currenttime);

	CLoginCenterConnect::Instance().Run();
	CLoginClientMgr::Instance().Run();
	CLogConnecter::Instance().Run();

	CLoginCenterConnect::Instance().EndRun();
	CLoginClientMgr::Instance().EndRun();
	CLogConnecter::Instance().EndRun();
}

void CLoginServer::Destroy()
{
	Exit();

	if (m_BackCommand)
	{
		m_BackCommand->~CBackCommand();
		free(m_BackCommand);
		m_BackCommand = NULL;
	}
}

static void ProcessCommand(lxnet::Socketer *sock, const char *commandstr);

static void back_dofunction(lxnet::Socketer *sock)
{
	MessagePack *pack;
	char commandstr[32];
	Msg *pmsg = sock->GetMsg();
	if (!pmsg)
		return;
	pack = (MessagePack *)pmsg;
	pack->Begin();
	pack->GetString(commandstr, sizeof(commandstr));
	commandstr[sizeof(commandstr) - 1] = 0;

	ProcessCommand(sock, commandstr);
}

bool CLoginServer::InitBackCommand()
{
	m_BackCommand = (CBackCommand *)malloc(sizeof(CBackCommand));
	if (!m_BackCommand)
		return false;
	new(m_BackCommand) CBackCommand();
	if (!m_BackCommand->Init(back_dofunction, CConfig::Instance().GetMonitorPort(), CConfig::Instance().GetPingTime(), CConfig::Instance().GetServerName()))
		return false;

	return true;
}

static void ProcessCommand(lxnet::Socketer *sock, const char *commandstr)
{
	static char s_buf[32 * 1024];
	short size = 0;
	MessagePack res;
	if (strcmp(commandstr, "help") == 0)
	{
		snprintf(s_buf, sizeof(s_buf) - 1, "help 帮助\nopenelapsed/closeelapsed 打开/关闭帧开销实时日志\ncurrentinfo 输出当前信息\nnetmeminfo 输出网络库内存使用情况\nallmeminfo 输出此程序内存池使用信息到文件\n");
		size = (short)strlen(s_buf) + 1;
		s_buf[size] = 0;
		res.PushString(s_buf);
		sock->SendMsg(&res);
	}
	else if (strcmp(commandstr, "openelapsed") == 0)
	{
		g_elapsed_log_flag = true;

		snprintf(s_buf, sizeof(s_buf) - 1, "帧开销实时日志已打开");
		size = (short)strlen(s_buf) + 1;
		s_buf[size] = 0;
		res.PushString(s_buf);
		sock->SendMsg(&res);
	}
	else if (strcmp(commandstr, "closeelapsed") == 0)
	{
		g_elapsed_log_flag = false;

		snprintf(s_buf, sizeof(s_buf) - 1, "帧开销实时日志已关闭");
		size = (short)strlen(s_buf) + 1;
		s_buf[size] = 0;
		res.PushString(s_buf);
		sock->SendMsg(&res);
	}
	else if (strcmp(commandstr, "currentinfo") == 0)
	{
		size = 0;

		CLoginCenterConnect::Instance().GetCurrentInfo(&s_buf[size], sizeof(s_buf) - size - 1);
		size = strlen(s_buf);
		CLoginClientMgr::Instance().GetCurrentInfo(&s_buf[size], sizeof(s_buf) - size - 1);
		s_buf[sizeof(s_buf) - 1] = 0;
		res.PushString(s_buf);
		sock->SendMsg(&res);
	}
	else if (strcmp(commandstr, "netmeminfo") == 0)
	{
		snprintf(s_buf, sizeof(s_buf) - 1, "%s", lxnet::net_get_memory_info(s_buf, sizeof(s_buf) - 1));
		size = (short)strlen(s_buf) + 1;
		s_buf[size] = 0;
		res.PushString(s_buf);
		sock->SendMsg(&res);
	}
	else if (strcmp(commandstr, "allmeminfo") == 0)
	{
		sPoolInfo.writeinfotofile();

		snprintf(s_buf, sizeof(s_buf) - 1, "所有内存信息已经写入到文件");
		size = (short)strlen(s_buf) + 1;
		s_buf[size] = 0;
		res.PushString(s_buf);
		sock->SendMsg(&res);
	}
	else
	{
		res.PushString(commandstr);
		sock->SendMsg(&res);
	}
}
