﻿#include "CenterServer.h"
#include "CentServerMgr.h"
#include "config.h"
#include "Timer.h"
#include "ServerLog.h"
#include "crosslib.h"
#include "ServerStatusMgr.h"
#include "ClientAuthMgr.h"
#include "LogConnecter.h"
#include "CenterPlayerMgr.h"
#include "NameCheckConnecter.h"
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

CCenterServer::CCenterServer()
{
	m_BackCommand = nullptr;
	m_Run = false;
}

CCenterServer::~CCenterServer()
{
	m_BackCommand = nullptr;
	m_Run = false;
}

static void cb()
{
	CCenterServer::Instance().Destroy();
}

bool CCenterServer::Init()
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

		if (!CCentServerMgr::Instance().Init(
			CConfig::Instance().GetServerIP(),
			CConfig::Instance().GetServerID(),
			CConfig::Instance().GetListenPort(),
			CConfig::Instance().GetOverTime()))
		{
			RunStateError("初始化 ServerMgr 失败!");
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

		if (!CNameCheckConnecter::Instance().Init(
			CConfig::Instance().GetNameCheckServerIP(),
			CConfig::Instance().GetNameCheckServerPort(),
			CConfig::Instance().GetNameCheckServerID(),
			CConfig::Instance().GetNameCheckServerName(),
			CConfig::Instance().GetServerID(),
			CConfig::Instance().GetServerType(),
			CConfig::Instance().GetServerName(),
			CConfig::Instance().GetPingTime(),
			CConfig::Instance().GetOverTime()))
		{
			RunStateError("初始化 NameCheckConnecter 失败!");
			break;
		}

		m_Run = true;
		return true;

	} while (true);

	CCentServerMgr::Instance().Destroy();
	CLogConnecter::Instance().Destroy();
	CNameCheckConnecter::Instance().Destroy();
	CClientAuthMgr::Instance().Destroy();
	CServerStatusMgr::Instance().Destroy();
	CCenterPlayerMgr::Instance().Destroy();
	Destroy();

	return false;
}

bool CCenterServer::Release()
{
	return true;
}

void CCenterServer::Run()
{
	const int normaldelay = 50;
	const int maxdelay = normaldelay * 2;
	int delay;
	while (m_Run)
	{
		CCentServerMgr::Instance().ResetMsgNum();
		CLogConnecter::Instance().ResetMsgNum();
		CNameCheckConnecter::Instance().ResetMsgNum();
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
			ElapsedLog("运行超时:%d\n%s日志服务器连接：%s名称检查服务器连接：%s", delay, 
				CCentServerMgr::Instance().GetMsgNumInfo(), 
				CLogConnecter::Instance().GetMsgNumInfo(),
				CNameCheckConnecter::Instance().GetMsgNumInfo());
		}
	}
	delaytime(300);

	CCentServerMgr::Instance().Destroy();
	CLogConnecter::Instance().Destroy();
	CNameCheckConnecter::Instance().Destroy();
	CClientAuthMgr::Instance().Destroy();
	CServerStatusMgr::Instance().Destroy();
	CCenterPlayerMgr::Instance().Destroy();

	Destroy();
}

void CCenterServer::Exit()
{
	m_Run = false;
}

void CCenterServer::RunOnce()
{
	lxnet::net_run();
	m_BackCommand->Run(g_currenttime);

	CCentServerMgr::Instance().Run();
	CLogConnecter::Instance().Run();
	CNameCheckConnecter::Instance().Run();

	CCentServerMgr::Instance().EndRun();
	CLogConnecter::Instance().EndRun();
	CNameCheckConnecter::Instance().EndRun();
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

bool CCenterServer::InitBackCommand()
{
	m_BackCommand = (CBackCommand *)malloc(sizeof(CBackCommand));
	if (!m_BackCommand)
		return false;
	new(m_BackCommand) CBackCommand();
	if (!m_BackCommand->Init(back_dofunction,CConfig::Instance().GetMonitorPort(),CConfig::Instance().GetPingTime(), CConfig::Instance().GetServerName()))
		return false;

	return true;
}

void CCenterServer::Destroy()
{
	Exit();

	if (m_BackCommand)
	{
		m_BackCommand->~CBackCommand();
		free(m_BackCommand);
		m_BackCommand = NULL;
	}
}

static void ProcessCommand(lxnet::Socketer *sock, const char *commandstr)
{
	static char s_buf[31 * 1024];
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

		CCentServerMgr::Instance().GetCurrentInfo(&s_buf[size], sizeof(s_buf) - size - 1);
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