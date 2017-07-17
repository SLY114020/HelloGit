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
	// 初始化
	bool init();
	bool suspend();
	bool run();

	static void func(ThreadData* data);

	bool isTerminate();
	bool finish;
	// 当前线程的句柄
	HANDLE hThread;
	DWORD threadid;
	ThreadData data;
};

