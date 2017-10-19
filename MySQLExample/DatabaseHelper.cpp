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

bool DatabaseHelper::Execute(const std::string &sql)
{
	try
	{
		pstmt = con->prepareStatement(sql);
		return pstmt->execute();
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

sql::ResultSet* DatabaseHelper::ExecuteQuery(const std::string &sql)
{
	try
	{
		pstmt = con->prepareStatement(sql);
		return pstmt->executeQuery();
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

/**
 * ExecuteUpdate
 * Executes the sql command from the string
 * @param message - the sql command
 * @return int - the number of rows affected
 */
int DatabaseHelper::ExecuteUpdate(const std::string &sql)
{
	try
	{
		pstmt = con->prepareStatement(sql);
		return pstmt->executeUpdate();
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