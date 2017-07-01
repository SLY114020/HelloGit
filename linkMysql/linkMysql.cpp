// linux下链接mysql 数据库方式
#include <mysql/mysql.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	// 差不多是初始化数据库吧
	MYSQL *connection = mysql_init(NULL);
	// 连接数据库
	connection = mysql_real_connect(connection, "localhost", "sly", "114020", "StudentInfo", 0, NULL, 0);
	if(connection == NULL)
	{
		cout<<"没有连接上mysql"<<endl;
		return 1;
	}
	cout<<"连接上了mysql"<<endl;
	// 执行查询语句
	int t = mysql_query(connection,  "select * from user;");
	if(t)
	{
		cout<<"出错了"<<endl;
		return 1;
	}
	cout<<"查询到了"<<endl;
	// 获取查询结果
	MYSQL_RES *res = mysql_use_result(connection);
	if(res)
	{
		for(int i = 0; i < mysql_field_count(connection); ++i)
		{
			// 获取下一行
			MYSQL_ROW row= mysql_fetch_row(res);
			if(row <= 0)
				break;
			// 遍历每个列元素
			for(int r = 0 ; r  < mysql_num_fields(res) ; r ++)
				cout<<row[r]<< " ";
			cout<<endl;
		}
	}
	// 释放掉结果
	mysql_free_result(res);
	return 0;
}
