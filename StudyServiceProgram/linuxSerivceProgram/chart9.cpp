#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <sys/epoll.h>
#include <pthread.h>
#include <fcntl.h>
#include <errno.h>
using namespace std;

/**
	select 操作
	int select();

	poll 操作
	int poll();

	epoll 操作
	创建
	int epoll_create(int size)
	控制事件表
	int epoll_ctl(int epfd, int op, int fd, struct epoll_event* event)
	等待函数
	int epoll_wait(int epfd, struct epoll_event* events, int maxevents, int timeout);
*/



void selectTest()
{
	int ss = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(10000);
	addr.sin_addr.s_addr = inet_addr("192.168.121.132");
	
	int ret = bind(ss, (struct sockaddr*)&addr, sizeof(sockaddr));
	if(ret < 0)
	{
		printf("bind error");
		return ;
	}
	listen(ss, 5);

	struct sockaddr_in c_addr;
	socklen_t len = sizeof(sockaddr_in);
	int cs;
	cs = accept(ss, (struct sockaddr*)&c_addr, &len);

	char buf[1024];
	fd_set read_fds;
	fd_set exception_fds;
	FD_ZERO(&read_fds);
	FD_ZERO(&exception_fds);

	while(true)
	{
		memset(buf, '\0', sizeof(buf));
		FD_ZERO(&read_fds);
		FD_ZERO(&exception_fds);
		ret = select(cs + 1, &read_fds, NULL, &exception_fds, NULL);
		if(ret < 0)
			break;
		if(FD_ISSET(cs, &read_fds))
		{
			ret = recv(cs, buf, sizeof(buf)-1, 0);
			if(ret < 0)
				break;
			printf("get %d bytes of data: %s\n", ret, buf);
		}
		else if (FD_ISSET(cs, &exception_fds))
		{
			ret = recv(cs, buf, sizeof(buf)-1, MSG_OOB);
			if(ret < 0)
				break;
			printf("get %d bytes of data: %s\n", ret, buf);

		}
	}
	close(cs);
	close(ss);
}

/*
#define MAX_EVENT_NUMBER 1024
#define BUFFER_SIZE 10
int setnonblocking(int fd)
{
	int old_option = fcntl(fd, F_GETFL);
	int new_option = old_option | O_NONBLOCK;
	fcntl(fd, F_SETFL, new_option);
	return old_option;
}

void addfd(int epollfd, int fd, bool enable_et)
{
	epoll_event event;
	event.data.fd = fd;
	event.events = EPOLLIN;
	if(enable_et)
	{
		event.events |= EPOLLET;
	}
	epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
	setnonblocking(fd);
}

void lt(epoll_event* events, int number, int epollfd, int listenfd)
{
	char buf[BUFFER_SIZE];
	for(int i = 0; i < number; i++)
	{
		int sockfd = events[i].data.fd;
		if(sockfd == listenfd)
		{
			struct sockaddr_in client_address;
			socklen_t client_len = sizeof(client_address);
			int connfd = accept(listenfd, (struct sockaddr*)&client_address, &client_len);
			addfd(epollfd, connfd, false);
		}
		else if (events[i].events & EPOLLIN)
		{
			printf("event trigger once\n");
			memset(buf, '\0', BUFFER_SIZE);
			int ret = recv(sockfd, buf, BUFFER_SIZE -1, 0);
			if(ret <= 0)
			{
				close(sockfd);
				continue;
			}
			printf("get %d bytes of content: %s \n", ret, buf);
		}
		else
		{
			printf("something else happend\n");
		}
	}
}

void et(epoll_event* events, int number, int epollfd, int listenfd)
{
	char buf[BUFFER_SIZE];
	for(int i = 0; i < number; i++)
	{
		int sockfd = events[i].data.fd;
		if(sockfd == listenfd)
		{
			struct sockaddr_in client_address;
			socklen_t client_len = sizeof(client_address);
			int connfd = accept(listenfd, (struct sockaddr*)&client_address, &client_len);
			addfd(epollfd, connfd, true);
		}
		else if (events[i].events & EPOLLIN)
		{
			printf("event trigger once\n");
			while(1)
			{
				memset(buf, '\0', BUFFER_SIZE);
				int ret = recv(sockfd, buf, BUFFER_SIZE -1, 0);
				if(ret < 0)
				{
					if( (errno == EAGAIN) || (errno == EWOULDBLOCK))
					{
						printf("read later\n");
						break;
					}
					close(sockfd);
					continue;
				}
				else if (ret == 0)
				{
					close(sockfd);
				}
				else
				{
					printf("get %d bytes of content: %s \n", ret, buf);
				}
			}
		}
		else
		{
			printf("something else happend\n");
		}
	}
}


void epollTest()
{
	int ss = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(10000);
	addr.sin_addr.s_addr = inet_addr("192.168.121.132");
	
	int ret = bind(ss, (struct sockaddr*)&addr, sizeof(sockaddr));
	if(ret < 0)
	{
		printf("bind error");
		return ;
	}
	listen(ss, 5);


	epoll_event events[MAX_EVENT_NUMBER];
	int epollfd = epoll_create(5);
	// 将监听socket放入
	//addfd(epollfd, ss, true);
	addfd(epollfd, ss, true);

	while(true)
	{
		int ret = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
		if(ret < 0)
		{
			printf("epoll_failure\n");
			break;
		}
		//lt(events, ret, epollfd, ss);
		et(events, ret, epollfd, ss);
	}

	close(ss);
}
*/

#define MAX_EVENT_NUMBER 1024
#define BUFFER_SIZE 1024
struct fds
{
	int epollfd;
	int sockfd;
};

int setnonblocking(int fd)
{
	int old_option = fcntl(fd, F_GETFL);
	int new_option = old_option | O_NONBLOCK;
	fcntl(fd, F_SETFL, new_option);
	return old_option;
}

void addfd(int epollfd, int fd, bool oneshot)
{
	epoll_event event;
	event.data.fd = fd;
	event.events = EPOLLIN | EPOLLET;
	if(oneshot)
	{
		event.events |= EPOLLONESHOT;
	}
	epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
	setnonblocking(fd);
}

void reset_oneshot(int epollfd, int fd)
{
	epoll_event event;
	event.data.fd = fd;
	event.events = EPOLLIN | EPOLLET | EPOLLONESHOT;
	epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &event);
}

void* worker(void* arg)
{
	int sockfd = ((fds*)arg)->sockfd;
	int epollfd = ((fds*)arg)->epollfd;
	printf("new thread to recv data on fd : %d\n", sockfd);
	char buf[BUFFER_SIZE];
	memset(buf, '\0', BUFFER_SIZE);

	while(true)
	{
		int ret = recv(sockfd, buf, BUFFER_SIZE -1, 0);
		if(ret < 0)
		{
			if( (errno == EAGAIN) || (errno == EWOULDBLOCK))
			{
				reset_oneshot(epollfd, sockfd);
				printf("read later\n");
				break;
			}
		}
		else if (ret == 0)
		{
			close(sockfd);
			printf("closed then connection\n");
			break;
		}
		else
		{
			printf("get %d bytes of content: %s \n", ret, buf);
			sleep(5);
		}
	}
	printf("end thread to recv data on fd: %d\n",sockfd);
	return NULL;
}

void epollTest()
{
	int ss = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(10000);
	addr.sin_addr.s_addr = inet_addr("192.168.121.132");
	
	int ret = bind(ss, (struct sockaddr*)&addr, sizeof(sockaddr));
	if(ret < 0)
	{
		printf("bind error");
		return ;
	}
	listen(ss, 5);


	epoll_event events[MAX_EVENT_NUMBER];
	int epollfd = epoll_create(5);
	// 将监听socket放入
	//addfd(epollfd, ss, true);
	addfd(epollfd, ss, false);

	while(true)
	{
		int ret = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
		if(ret < 0)
		{
			printf("epoll_failure\n");
			break;
		}
		for(int i = 0; i < ret; ++i)
		{
			int sockfd = events[i].data.fd;
			if(sockfd == ss)
			{
				struct sockaddr_in client_address;
				socklen_t client_len = sizeof(client_address);
				int connfd = accept(ss, (struct sockaddr*)&client_address, &client_len);
				addfd(epollfd, connfd, true);
			}
			else if( events[i].events & EPOLLIN)
			{
				pthread_t thread;
				fds fds_for_new_worker;
				fds_for_new_worker.epollfd = epollfd;
				fds_for_new_worker.sockfd = sockfd;
				pthread_create(&thread, NULL, worker, (void*)&fds_for_new_worker);
			}
			else
			{
				printf("unknow thing\n");
			}
		}
	}

	close(ss);
}

int main()
{
	epollTest();
	return 1;
}


