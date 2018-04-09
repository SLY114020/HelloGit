#include <mysql/mysql.h>

class MySql
{
public:
	MySql(){ connection = mysql_init(NULL); }

	bool connect(std::string& host, std::string& user_name, std::string& password, std::string& database)
	{
		connection = mysql_real_connect(connection, host, user_name, password, database, 0, NULL, 0);
		return connection != NULL;
	}

	MYSQL *connection;
};