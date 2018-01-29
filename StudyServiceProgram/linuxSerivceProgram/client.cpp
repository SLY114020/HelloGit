#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

int client()
{
	int cs = socket(AF_INET, SOCK_STREAM, 0);
	if(cs < 0)
	{
		printf("create socket fail");
		return 0;
	}

	struct sockaddr_in s_addr;
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(10000);
	s_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	int ss = connect(cs, (struct sockaddr*)&s_addr, sizeof(sockaddr));
	if(ss < 0)
	{
		printf("connect fail");
		return 1;
	}

	char buff[512];
	memset(buff, 'a', 512);
	send(cs, buff, 512, 0);
	
	close(cs);
			
	return 0;
}


int daytimeclient()
{
	int cs = socket(AF_INET, SOCK_STREAM, 0);
	if(cs < 0)
	{
		printf("create socket fail");
		return 0;
	}

	struct hostent* hostinfo = gethostbyname("localhost");

	struct servent* servinfo = getservbyname("daytime", "tcp");
	if(!servinfo)
	{
		printf("servinfo not find\n");
		return 0;
	}

	struct sockaddr_in s_addr;
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = servinfo->s_port;
	s_addr.sin_addr = *(struct in_addr*)*hostinfo->h_addr_list;
	printf("ip:%s, port:%d\n", inet_ntoa(*(struct in_addr*)*hostinfo->h_addr_list) ,servinfo->s_port);

	int ss = connect(cs, (struct sockaddr*)&s_addr, sizeof(sockaddr));
	if(ss < 0)
	{
		printf("connect fail");
		return 1;
	}

	char buff[128];
	read(cs, buff, 128);
	printf("%s \n", buff);
	
	close(cs);
			
	return 0;
}

/* I/O
   pipe
   dup
*/

int duptest()
{
	int cs = socket(AF_INET, SOCK_STREAM, 0);
	if(cs < 0)
	{
		printf("create socket fail");
		return 0;
	}

	struct hostent* hostinfo = gethostbyname("localhost");

	struct servent* servinfo = getservbyname("daytime", "tcp");
	if(!servinfo)
	{
		printf("servinfo not find\n");
		return 0;
	}

	struct sockaddr_in s_addr;
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = servinfo->s_port;
	s_addr.sin_addr = *(struct in_addr*)*hostinfo->h_addr_list;
	printf("ip:%s, port:%d\n", inet_ntoa(*(struct in_addr*)*hostinfo->h_addr_list) ,servinfo->s_port);

	int ss = connect(cs, (struct sockaddr*)&s_addr, sizeof(sockaddr));
	if(ss < 0)
	{
		printf("connect fail");
		return 1;
	}

	char buff[128];
//	read(cs, buff, 128);
	close(STDOUT_FILENO);
	dup(cs);
	scanf("%s", buff);
	dup(STDOUT_FILENO);
	printf("%s \n", buff);
	
	close(cs);
}

int main()
{
//	client();
//	daytimeclient();
	duptest();
	return 0;
}





