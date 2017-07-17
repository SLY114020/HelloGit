#pragma once

#include "stdafx.h"

class MyThread;

typedef struct ThreadData{
	MyThread* t;
}ThreadData;

class MyThread
{
public:
	MyThread();
	~MyThread();
	// ��ʼ��
	bool init();
	bool suspend();
	bool run();

	static void func(ThreadData* data);

	bool isTerminate();
	bool finish;
	// ��ǰ�̵߳ľ��
	HANDLE hThread;
	DWORD threadid;
	ThreadData data;
};

