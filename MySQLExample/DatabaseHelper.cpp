#include "DatabaseHelper.h"

#include <iostream>

using namespace std;

DatabaseHelper::DatabaseHelper()
{

}

DatabaseHelper::~DatabaseHelper()
{

}

bool DatabaseHelper::ConnectToDatabase(const std::string &server,
	const std::string &username,
	const std::string &password,
	const std::string &schema)
{
	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		con->setSchema(schema);
	}
	catch (sql::SQLException &exception)
	{
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << exception.what();
		cout << " (MySQL error code: " << exception.getErrorCode();
		cout << ", SQLState: " << exception.getSQLState() << " )" << endl;
		return false;
	}

	return true;
}

int DatabaseHelper::ExecuteStatement(const std::string &message)
{
	try
	{
		pstmt = con->prepareStatement(message);
		pstmt->executeUpdate();
	}
	catch (sql::SQLException &exception)
	{
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << exception.what();
		cout << " (MySQL error code: " << exception.getErrorCode();
		cout << ", SQLState: " << exception.getSQLState() << " )" << endl;
		return false;
	}
}