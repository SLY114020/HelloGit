#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
	字节序转换函数
	htonl()
	htons()
	ntohl()
	ntohs()
	ip 地址转换函数
	// ip->int
	inet_addr
	inet_aton
	// int->ip
	inet_ntoa
*/
/**
	gethostbyname()
	gethostbyaddr()
	
	// 获取服务名称
	getservbyname()
	getservbyport()

	getaddrinfo

	// 大量读，大量写
	readv   writev

	// 貌似socket传送文件
	sendfile(int socket, int filefd,...)

	// 共享内存
	// mmap   munmap
	
	用于内存数据移动
	splice()


*/

void testIpInt()
{
	int ip = inet_addr("192.168.1.1");
	in_addr in_a;
	in_a.s_addr = ip;
	char* c_ip = inet_ntoa(in_a);
	printf("ip:%s\n", c_ip);
}

void byteorder()
{
	union
	{
		short value;
		char union_bytes[sizeof(short)];
	}test;
	test.value = 0x0102;
	if(test.union_bytes[0] == 1 && test.union_bytes[1] == 2)
		printf("big endian\n");
	else 
		printf("little endian\n");
}

void server()
{
	int ss = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(10000);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
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
	cs = accept(ss, (struct sockaddr*)&c_addr, &len);
	if(cs < 0)
	{
		printf("accept error");
		return ;
	}
	printf("ip:%s, port:%d\n", inet_ntoa(c_addr.sin_addr), ntohs(c_addr.sin_port));
	char buff[1024];
	memset(buff, '\0', 1024);
	while(recv(cs, buff, 1024-1,0) > 0){}
	printf("%s\n", buff);
	close(cs);
	close(ss);
}

void C7_1()
{
	uid_t uid = getuid();
	uid_t euid = geteuid();
	printf("userid is %d, effective userid is : %d\n", uid, euid);

	char buff[128];
	char* path = getcwd(buff, 128);
}

int main()
{
	//byteorder();
//	testIpInt();
//	server();
	C7_1();
	return 1;
}


