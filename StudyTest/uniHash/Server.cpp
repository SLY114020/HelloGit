#include "stdafx.h"
#include "Server.h"
#include <stdio.h>
#include <time.h>

Server::Server()
{
	srand((int)time(0));
}


Server::~Server()
{
}

void Server::addNewSerice()
{
	Service* newS = new Service;
	uint32 id = 0;
	while (id == 0)
	{
		id = rand() % UINT_MAX;
		auto it = s.find(id);
		if (it == s.end())
			break;
		id = 0;
	}
	newS->id = id;
	s.insert(std::make_pair(id, newS));
	newS->addNewID(id);
	//addVirtualSerice(newS);
}

void Server::addVirtualSerice(Service* newS)
{
	uint32 num = 2;
	while (num)
	{
		uint32 id = 0;
		while (id == 0)
		{
			id = rand() % UINT_MAX;
			auto it = s.find(id);
			if (it == s.end())
				break;
			id = 0;
		}
		newS->addNewID(id);
		s.insert(std::make_pair(id, newS));
		num--;
	}
}


void Server::removeSerice(uint32 id)
{
	auto it = s.find(id);
	if (it == s.end())
		return;
	Service* del_s = it->second;
	for (auto it = del_s->serid.begin(); it != del_s->serid.end(); ++it)
	{
		auto s_it = s.find(id);
		if (s_it != s.end())
		{
			s.erase(s_it);
		}
	}
	delete del_s; 
}


void Server::addNewUser()
{
	if (s.size() == 0)
		return;
	uint32 id = 0;
	while (id == 0)
	{
		id = rand() % UINT_MAX;
		auto it = uid.find(id);
		if (it == uid.end())
			break;
		id = 0;
	}
	uid.insert(id);

	User u;
	u.id = id;
	u.name = "id:" + id;
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		if (id < it->first)
		{
			if (it->second)
			{
				it->second->addUser(u);
				return;
			}
		}
	}
	auto first = s.begin();
	first->second->addUser(u);
}

void Server::display()
{
	system("cls");
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		if (it->first == it->second->id)
		{
			std::cout << "serice" << it->first << std::endl;
			std::cout << it->second->size() << std::endl;
			std::cout << it->second->vsSize() << std::endl;
		}
	}
}


Service*  Server::getRandomSerice()
{
	uint32 id = rand() % s.size();
	uint32 count = 0;
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		if (id == count)
			return it->second;
		count++;
	}
	return 0;
}

uint32 Server::getSericeNextSerice(Service* cs)
{
	bool find_cur = false;
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		if (cs->id == it->first)
			find_cur = true;
		if (find_cur && cs != it->second)
		{
			return it->first;
		}
	}
	return s.begin()->first;
}

uint32 Server::getUserBySerice(uint32 s_id)
{
	auto it = s.find(s_id);
	if (it->second->size() == 0)
		return 0;
	auto u_it = it->second->user_data.begin();
	return u_it->first;
}

bool Server::userInSerice(uint32 uid, uint32 s_id)
{
	auto it = s.find(s_id);
	auto u_it = it->second->user_data.find(uid);
	return u_it != it->second->user_data.end();
}
