// uniHash.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Server.h"
#include "Service.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Server s;
	s.addNewSerice();
	s.addNewSerice();
	s.addNewSerice();
	for (int i = 0; i < 100; ++i)
	{
		s.addNewUser();
	}
	s.display();
	Sleep(2000);
	Service* serice = s.getRandomSerice();
	uint32 uid = s.getUserBySerice(serice->id);
	uint32 nextsid = s.getSericeNextSerice(serice);
	Service* nexts = s.getSerice(nextsid);
	nexts->copy(serice);
	s.removeSerice(serice->id);
	s.display();
	std::cout << s.userInSerice(uid, nexts->id) << std::endl;

	return 0;
}

