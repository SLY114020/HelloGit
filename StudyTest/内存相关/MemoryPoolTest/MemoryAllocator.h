#pragma once

class MemoryAllocator
{
public:
	MemoryAllocator();
	~MemoryAllocator();

	void* operator new(size_t size);
	void operator delete(void* p);
};

