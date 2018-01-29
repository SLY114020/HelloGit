#ifndef HTTP_CONNECTION_H
#define HTTP_CONNECTION_H

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mmna.h>
#include <stdarg.h>
#include <errno.h>

#include "locker.h"

class http_conn
{
public:
	// file max len
	static const int FILENAME_LEN = 200;
	// read buffer size
	static const int READ_BUFFER_SIZE = 2048;
	// write buffer size
	static const int WRITE_BUFFER_SIZE = 1024;
	// http request func 
	enum METHOD{GET = 0, POST, HEAD, PUT, DELETE, TRACE, OPTIONS, CONNECT, PATCH};
	// 
	enum CHECK_STATE{CHECK_STATE_REQUESTLINE = 0, CHECK_STATE_HEADER, CHECK_STATE_CONTENT};
	//
	enum HTTP_CODE{NO_REQUEST, GET_REQUEST, BAD_REQUEST, NO_RESOURCE, FORBIDDEN_REQUEST, FILE_REQUEST, INTERNAL_ERROR, CLOSED_CONNECTION};
	//
	enum LINE_STATUS = { LINE_OK = 0, LINE_BAD, LINE_OPEN};
public:
	http_conn(){}
	~http_conn(){}

public:
	// 连接
	void init(int sockfd, const sockaddr_in& addr);
	// 关闭
	void close_conn(bool real_close = true);
	// 处理客户请求
	void process();
	// 
	bool read();
	bool write();
private:
	// 初始化连接
	void init();
	// 解析 HTTP请求
	HTTP_CODE process_read();
	// 填充 HTTP 应答
	bool process_write(HTTP_CODE ret);

	//
	HTTP_CODE parse_request_line(char* text);
	HTTP_CODE parse_headers(char* text);
	HTTP_CODE parse_content(char* text);
	HTTP_CODE do_request();
	char* get_line() {return m_read_buf + m_start_line;}
	LINE_STATUS parse_line();

	//
	void unmap();
	bool add_response(const char* format, ...);
	bool add_content(const char* content);
	bool add_status_line(int status, const char* title);
	bool add_headers(int content_length);
	bool add_content_length(int content_length);
	bool add_linger();
	bool add_blank_line();

public:
	static int m_pollfd;
	static int m_user_count;

private:
	int m_sockfd;
	sockaddr_in m_address;
};


#endif









