// Thread.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "MyTreahPool.h"
#include "MyThread.h"
#include <map>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	MyThreahPool pool(3);
	pool.getAllThreadid();
	while (true)
	{
		char t = getchar();
		bool need_break =false;
		switch (t)
		{
		case 'r':
		{
					int i;
					cout <<"选择要开启的线程"<< endl;
					cin >> i;
					pool.runThread(i);
					break;

		}
		case 's':
		{
					int i;
					cout << "选择要关闭的线程" << endl;
					cin >> i;
					pool.stopThread(i);
					break;
		}
		case 'e':
			need_break = true;
			break;
		default:
			break;
		}
		if (need_break)
			break;
	}
	return 0;
}

