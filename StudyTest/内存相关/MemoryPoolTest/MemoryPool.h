#pragma once

#include "sDefine.h"
#include "stdafx.h"

struct node{
	DWORD start;
	DWORD end;
	bool  use;
	node* next;
};

class MemoryPool
{
public:
	MemoryPool();
	~MemoryPool();
	bool allocate(DWORD size, DWORD block_size);
	node* head;
};

