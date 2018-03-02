

#include <iostream>
#include <pthread.h>
#include <thread>

class NonCopyable
{
public:
	NonCopyable() = default;
	NonCopyable(const NonCopyable& copy) = delete;
	NonCopyable* operator=(const NonCopyable& copy) = delete;
};


class Mutex: public NonCopyable
{
public:
	Mutex()
	{
		pthread_mutex_init(&mutex, NULL);
	}
	~Mutex()
	{
		pthread_mutex_destroy(&mutex);
	}
	void lock()
	{
		pthread_mutex_lock(&mutex);
	}
	void unlock()
	{
		pthread_mutex_unlock(&mutex);
	}
private:
	pthread_mutex_t mutex;
}mutex;

class MutexLockGuard: public NonCopyable
{
public:
	explicit MutexLockGuard(Mutex& mutex):_mutex(mutex){
		_mutex.lock();
	}
	~MutexLockGuard()
	{
		_mutex.unlock();
	}
private:
	Mutex& _mutex;
};

int i = 0;

void handler()
{
	while(i <= 10)
	{
		mutex.lock();
		if(i > 10)
		{
			mutex.unlock();
			break;
		}
		i = i + 1;
		std::cout<<i<<std::endl;
		mutex.unlock();
	}
}

int main()
{
	// C++11 下   编写的线程
	for(int j = 0; i < 2; ++j)
	{
		std::thread t(handler);
		t.join();
	}

//  linux 下  pthread 写法
//	pthread_t tid;
//	for(int j = 0; i < 2; j++)
//	{
//		pthread_create(&tid, NULL, handler, NULL);
//		pthread_detach(tid);
//	}
	while(i <= 10);
	return 1;
}

