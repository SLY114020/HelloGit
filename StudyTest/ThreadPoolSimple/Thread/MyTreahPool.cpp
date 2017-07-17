#include "stdafx.h"
#include "MyTreahPool.h"


MyThreahPool::MyThreahPool(int size)
{
	for (int i = 0; i < size; ++i)
	{
		MyThread* t = new MyThread;
		if (t && t->init())
		{
			thread_map.insert(std::make_pair(t->threadid, t));
		}
	}
}

MyThreahPool::~MyThreahPool()
{
	auto it = thread_map.begin();
	auto it_end = thread_map.end();
	for (; it != it_end; ++it)
	{
		delete it->second;
	}
	thread_map.clear();
}

void MyThreahPool::getAllThreadid()
{
	auto it = thread_map.begin();
	auto it_end = thread_map.end();
	for (; it != it_end; ++it)
	{
		cout << it->first << endl;
	}
}

void MyThreahPool::runThread(DWORD threadid)
{
	auto it = thread_map.find(threadid);
	if (it == thread_map.end())
		return;
	it->second->run();
}

void MyThreahPool::stopThread(DWORD threadid)
{
	auto it = thread_map.find(threadid);
	if (it == thread_map.end())
		return;
	it->second->suspend();
}