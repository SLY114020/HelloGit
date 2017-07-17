#include "stdafx.h"
#include "MyThread.h"


MyThread::MyThread()
{
	hThread = NULL;
	threadid = NULL;
	finish = false;
}

MyThread::~MyThread()
{
	TerminateThread(hThread, 0);
}

bool MyThread::init()
{
	data.t = this;
	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)func, &data, CREATE_SUSPENDED, &threadid);
	if (hThread == NULL)
		return false;
	return true;
}

bool MyThread::isTerminate()
{
	return finish;
}

bool MyThread::run()
{
	if (!hThread)
		return false;
	ResumeThread(this->hThread);
	return true;
}

bool MyThread::suspend()
{
	if (!hThread)
		return false;
	SuspendThread(this->hThread);
	return true;
}

void MyThread::func(ThreadData* data)
{
	while (!data->t->isTerminate())
	{
		cout << data->t->threadid<< " ";
		Sleep(1000);
	}
}