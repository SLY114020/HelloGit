#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
using namespace std;

void testIpInt()
{
	int ip = inet_addr("192.168.1.1");
	in_addr in_a;
	in_a.s_addr = ip;
	char* c_ip = inet_ntoa(in_a);
	printf("ip:%s\n", c_ip);
}

void server()
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

	int cs;
	struct sockaddr_in c_addr;
	socklen_t len = sizeof(sockaddr_in);
	while(true)
	{
		cs = accept(ss, (struct sockaddr*)&c_addr, &len);
		if(cs < 0)
		{
			printf("accept error");
			return ;
		}
		printf("ip:%s, port:%d\n", inet_ntoa(c_addr.sin_addr), ntohs(c_addr.sin_port));

		std::string str="HTTP/1.1 200 OK\r\nDate: Sat, 31 Dec 2005 23:59:59 GMT\r\nContent-Type:text/html;charset=utf-8\r\nContent-Length:122\r\n\r\n<html><head><title>HelloWorld</title><body>What's your name</body></head></html>";
		
		send(cs, str.c_str(), str.size(), 0);
	}
	close(cs);
	close(ss);
}

int main()
{
	//byteorder();
//	testIpInt();
	server();
	return 1;
}


