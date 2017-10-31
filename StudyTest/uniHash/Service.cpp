#include "stdafx.h"
#include "Service.h"


Service::Service()
{
}


Service::~Service()
{
}

void Service::addUser(User user)
{
	user_data[user.id] = user;
}

void Service::addNewID(uint32 id)
{
	serid.insert(id);
}

void Service::copy(Service* s)
{
	for (auto it = s->user_data.begin(); it != s->user_data.end(); ++it)
		addUser(it->second);
}

uint32 Service::size()
{
	return user_data.size();
}
