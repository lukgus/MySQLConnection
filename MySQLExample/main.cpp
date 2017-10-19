#include <iostream>
#include <string>

#include "DatabaseHelper.h"

using namespace std;

DatabaseHelper dbHelper;

void ExampleInsert()
{
	dbHelper.ExecuteUpdate("INSERT INTO user(name, password) VALUES ('Lukas', 'SecurePassword');");
}

void ExampleSelect()
{
	sql::ResultSet* result = dbHelper.ExecuteQuery("SELECT * FROM user;");

	if (result->rowsCount() > 0)
	{
		while (result->next())
		{
			string name = result->getString(2);
			string password = result->getString(3);

			cout << "Name: " << name << endl;
			cout << "Password: " << password << endl;
		}
	}
}

void ExampleUpdate()
{
	int numUpdates = dbHelper.ExecuteUpdate("UPDATE user SET last_login_time = now();");
}

void MySQLExample()
{
	ExampleUpdate();

	int breakpoint = 0;
}

int main()
{
	if (!dbHelper.ConnectToDatabase("127.0.0.1:3306", "root", "root", "authentication"))
	{
		cout << "Failed to connect to the database!" << endl;
		return 1;
	}

	MySQLExample();

	return 0;
}