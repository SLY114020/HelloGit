#pragma once
#include "define.h"
#include "Service.h"

class Server
{
public:
	Server();
	~Server();

	void addNewSerice();
	void addVirtualSerice(Service* newS);
	void removeSerice(uint32 id);

	void addNewUser();

	Service* getSerice(uint32 id)
	{
		return s.find(id)->second;
	}
	Service* getRandomSerice();
	uint32 getSericeNextSerice(Service* cs);
	uint32 getUserBySerice(uint32 s_id);
	bool userInSerice(uint32 uid, uint32 s_id);
	void display();

private:
	// 记录所有服务
	std::map<uint32, Service*> s;
	// 记录所有id
	std::set<uint32> uid;
};

