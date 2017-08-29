

#include <iostream>
#include <pthread.h>
using namespace std;

class Mutex
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

int i = 0;

void* handler(void* arg)
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
		cout<<i<<endl;
		mutex.unlock();
	}
}

int main()
{

	pthread_t tid;
	for(int j = 0; i < 2; j++)
	{
		pthread_create(&tid, NULL, handler, NULL);
		pthread_detach(tid);
	}
	while(i <= 10);
	return 1;
}

