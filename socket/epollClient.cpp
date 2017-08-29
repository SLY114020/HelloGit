
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
using namespace std;

int cfd[1000] = {-1};

void* handler(void* arg)
{
	int* index = (int*)arg;
	while(true)
	{
		for(int i = *index; i < (*index+1) * 100; ++i)
		{
			if(cfd[i] == -1)
				continue;
			srand((int)time(0));
			if(rand() % 10000 > 100)
				continue;
			char buf[100];
			sprintf(buf,"hello World %d",i);
			write(cfd[i],buf,strlen(buf));
		}
		sleep(1);
	}
}

int main()
{
	int recbytes;
	int sin_size;
	char buffer[1024] = {0};
	struct sockaddr_in s_add, c_add;
	unsigned short portnum = 20000;
	bzero(&s_add, sizeof(struct sockaddr_in));
	s_add.sin_family = AF_INET;
	s_add.sin_addr.s_addr = inet_addr("127.0.0.1");
	s_add.sin_port = htons(portnum);
	for(int i = 0; i < 1000; i++)
	{
		cfd[i] = socket(AF_INET, SOCK_STREAM, 0);
		if(-1 == cfd[i])
		{
			return -1;
		}
		if(-1 == connect(cfd[i], (struct sockaddr*)(&s_add), sizeof(struct sockaddr)))
		{
			cout<<"connect fail"<<endl;
			return -1;
		}
	}
	for(int i = 0; i < 10 ; i ++)
	{
		pthread_t t_a;
		pthread_create(&t_a,NULL,handler,(void *)&(i));
		pthread_detach(t_a);
	}
	while(true) ;
	if(-1 == (recbytes = read(cfd[1],buffer,1024)))
	{
		    printf("read data fail !\r\n");
			    return -1;
	}
	printf("read ok\r\nREC:\r\n");
	buffer[recbytes]='\0';
	printf("%s\r\n",buffer);
	getchar();
	close(cfd[1]);
	return 0;
}
