// Alogith.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void CompareString(const char* str1, const char* str2)
{
	int size = strlen(str1) / sizeof(char);
	int size2 = strlen(str2) / sizeof(char);
	int i = 0;
	int j = 0;
	bool have_find = false;
	while(i < size)
	{
		for (; j < size2; ++j)
		{
			if (str1[i] != str2[j])
				break;
			i++;
			if (j + 1 == size2)
			{
				have_find = true;
				break;
			}
		}
		if (have_find)
			break;
		i++;
	}
	cout <<"开始位置" <<i - size2 << "结束位置"<< i << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char* str1 = "absdfwerqwesdf";
	char* str2 = "qwe";
	CompareString(str1, str2);
	return 0;
}

