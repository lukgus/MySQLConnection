#include <iostream>

#include "DatabaseHelper.h"

using namespace std;

DatabaseHelper dbHelper;

void MySQLExample()
{
	dbHelper.ExecuteStatement("INSERT INTO user(name, password) VALUES ('Lukas', 'SecurePassword');");
	int breakpoint = 0;
}

int main()
{
	if (!dbHelper.ConnectToDatabase("127.0.0.1:3306", "root", "", "authentication"))
	{
		cout << "Failed to connect to the database!" << endl;
		return 1;
	}

	MySQLExample();

	return 0;
}