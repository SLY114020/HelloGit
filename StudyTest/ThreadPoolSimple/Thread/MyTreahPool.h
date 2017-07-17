#pragma once

#include"stdafx.h"
#include <map>
#include "MyThread.h"

class MyThreahPool
{
public:
	MyThreahPool(int size = 1);
	~MyThreahPool();
	void getAllThreadid();
	void runThread(DWORD threadid);
	void stopThread(DWORD threadid);

	std::map<DWORD, MyThread*> thread_map;
};

