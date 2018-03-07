﻿#pragma once
#include "sqlinterface.h"
struct Msg;
class blockbuf;
class task
{
public:
	 task ();
	 ~task ();

	 enum
	 {
		 //需要处理的类型
		 tasktype_process = 0,

		 //转发类型
		 tasktype_transmit = 1,

		 //有连接断开
		 tasktype_serverdisconnect = 2,
	 };

	 static bool InitPools ();

	 static void DestroyPools ();

	 //设置一些必须的附带信息
	 void SetInfo (DataBase::CConnection *con, int serverid, int clientid = 0);

	 //获取数据库操作句柄
	 DataBase::CConnection *GetDBHand () { return m_con; }

	 //获取此任务来自哪个服务器
	 int GetServerID () { return m_serverid; }

	 //获取此任务来自哪个client
	 int GetClientID() { return m_clientid; }

	 //设置是否需要发送
	 void SetAsNeedSend (bool flag);

	 //是否需要发送
	 bool IsNeedSend () { return m_needsend; }

	 //设置是否发送到所有连接，默认只发送到关联的连接
	 void SetSendToAll (bool flag);

	 //是否发送到所有连接
	 bool IsSendToAll () { return m_sendtoall; }

	 //设置此任务的类型
	 void SetTaskType (int type) { m_tasktype = type; }

	 //是否是转发类型
	 bool IsTransmit () { return m_tasktype == tasktype_transmit; }

	 //是否需要执行此任务
	 bool IsProcess () { return m_tasktype == tasktype_process; }

	 //是否是连接断开
	 bool IsServerDisconnect () { return m_tasktype == tasktype_serverdisconnect; }

	 //重置
	 void Reset ();

	 //装入一个消息
	 void PushMsg (Msg *pMsg);

	 //获取一个消息
	 Msg *GetMsg ();

private:
	void CheckBlockNull ();
	int getdata (char *buf, int len);
	void Destroy ();

private:
	DataBase::CConnection *m_con;

	int m_tasktype;
	bool m_needsend;
	bool m_sendtoall;
	int m_serverid;
	int m_clientid;

///////////////////////////////////////
	blockbuf *m_head;
	blockbuf *m_currentforpush;
	blockbuf *m_currentforget;
};

task *task_create ();

void task_release (void *self);