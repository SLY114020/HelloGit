#pragma once
#include "define.h"

class Service
{
public:
	uint32 id;

	Service();
	~Service();

	void addUser(User user);
	
	void copy(Service* s);
	uint32 size();

	uint32 vsSize(){ return serid.size(); }

	void addNewID(uint32 id);

	std::set<uint32> serid;
	std::map<uint32, User> user_data;
};

