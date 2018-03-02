#include "stdafx.h"
#include "configFile.h"
#include <stdlib.h>
#include <stdio.h>
#include<string>


configFile::configFile(const char* filename)
{
	loadfile(filename);
}


configFile::~configFile()
{
}

char* configFile::getConfigByName(const char* key)
{
	auto it = config.find(key); 
	if (it == config.end())
		return NULL;
	return (char*)(*it).second.c_str();
}


void configFile::loadfile(const char* filename)
{
	FILE *file = fopen(filename, "r");
	if (!file)
	{
		printf("打开文件失败\n");
		return;
	}
	char buf[256];
	// 读取文件
	while (true)
	{
		char* p = fgets(buf, 256, file);
		if (!p)
			break;

		int ret = parseLine(buf);
		if (ret != OK)
		{
			printf("解析有问题\n");
			break;
		}
	}
	fclose(file);
}

int configFile::parseLine(char* pCh)
{
	int len = strlen(pCh) - 1;
	if (len <= 0)
		return OK;
	if (pCh[0] == '#')
		return OK;
	char* eq_s = strchr(pCh, '=');
	if (eq_s == NULL)
		return NoEqual;
	*eq_s = '\0';
	char* key = trimSpace(pCh);
	char* value = trimSpace(eq_s + 1);
	if (key && value)
		config.insert(std::make_pair(key, value));
	else
		return trimQuestion;
	return OK;
}

char* configFile::trimSpace(char* pCh)
{
	char* begin = pCh;
	while ((*begin == ' ') || (*begin == '\t'))
		++begin;

	char* end = begin + strlen(begin) - 1;
	while ((*end == ' ') || (*end) == '\t')
	{
		*end = '\0';
		--end;
	}
	int len = end - begin + 1;
	if (len < 0)
		return NULL;
	return begin;
}
