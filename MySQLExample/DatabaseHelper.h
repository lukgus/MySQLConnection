#ifndef DATABASE_HELPER_HG
#define DATABASE_HELPER_HG

#include <cppconn\driver.h>
#include <cppconn\exception.h>
#include <cppconn\resultset.h>
#include <cppconn\statement.h>
#include <cppconn\prepared_statement.h>

#include <string>

class DatabaseHelper
{
public:
	DatabaseHelper();
	~DatabaseHelper();

	bool ConnectToDatabase(const std::string &server, const std::string &username, const std::string &password, const std::string &schema);

	bool Execute(const std::string &message);
	sql::ResultSet* ExecuteQuery(const std::string &message);
	int ExecuteUpdate(const std::string &message);

private:
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
};

#endif
