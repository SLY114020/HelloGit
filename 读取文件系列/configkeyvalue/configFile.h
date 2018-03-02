#pragma once

#include <map>

class configFile
{
public:
	enum Error{
		OK,
		UnKnow,
		NoEqual,
		trimQuestion,
	};
	configFile(const char* filename);
	~configFile();
	
	char* getConfigByName(const char* key);

private:
	void loadfile(const char* filename);
	int parseLine(char* pCh);
	char* trimSpace(char* pCh);

	std::map<std::string, std::string> config;
};

