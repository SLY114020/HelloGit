// linux������mysql ���ݿⷽʽ
#include <mysql/mysql.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	// ����ǳ�ʼ�����ݿ��
	MYSQL *connection = mysql_init(NULL);
	// �������ݿ�
	connection = mysql_real_connect(connection, "localhost", "sly", "114020", "StudentInfo", 0, NULL, 0);
	if(connection == NULL)
	{
		cout<<"û��������mysql"<<endl;
		return 1;
	}
	cout<<"��������mysql"<<endl;
	// ִ�в�ѯ���
	int t = mysql_query(connection,  "select * from user;");
	if(t)
	{
		cout<<"������"<<endl;
		return 1;
	}
	cout<<"��ѯ����"<<endl;
	// ��ȡ��ѯ���
	MYSQL_RES *res = mysql_use_result(connection);
	if(res)
	{
		for(int i = 0; i < mysql_field_count(connection); ++i)
		{
			// ��ȡ��һ��
			MYSQL_ROW row= mysql_fetch_row(res);
			if(row <= 0)
				break;
			// ����ÿ����Ԫ��
			for(int r = 0 ; r  < mysql_num_fields(res) ; r ++)
				cout<<row[r]<< " ";
			cout<<endl;
		}
	}
	// �ͷŵ����
	mysql_free_result(res);
	return 0;
}
