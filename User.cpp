#include "User.h"
#include <iostream>
#include <string>
#include "sha256.h"
#include <sqlite3.h>
#include <format>
using namespace std;

void User::set_username()
{
	
	string uname;
	//TODO: Open database and check user names to see if it is all ready taken
	cout << "Type in your new username: ";
	getline(cin, uname);

	username = uname;

}

std::string User::get_username()
{
	return username;
}

void User::input_password()
{
	string pwd;
	cout << "Enter your new password: ";
	getline(cin, pwd);

	hashed_password_input = sha256(pwd);
}

std::string User::get_hash()
{
	return hashed_password_input;
}

int User::add_to_table(std::string uname, std::string pwd_hash, DB dname)
{

	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	string sql;

	// Open database
	rc = sqlite3_open(dname.get_name().c_str(), &db);

	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return (0);
	}
	else
	{
		fprintf(stderr, "Opened database successfully\n");
	}

	// Create SQL statement
	sql = format("INSERT INTO users (username, password_hash) " \
		"VALUES ('{}', '{}' );", username, hashed_password_input);

	// Exectute SQL statement
	rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		fprintf(stdout, "Records created successfully\n");
	}

	sqlite3_close(db);
	return 0;
}

int User::create_username_vector(string uname, DB dname)
{
	sqlite3* db;
	sqlite3_stmt* stmt;
	string sql = "SELECT username from sqlite_master WHERE name = 'users';";

	int rc = sqlite3_open(dname.get_name().c_str(), &db);

	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return (0);
	}
	else
	{
		fprintf(stderr, "Opened database successfully\n");
	}

	// Prepared statement
	rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &stmt, nullptr);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		return (0);
	}
	else
	{
		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
		{
			unameVec.push_back(sqlite3_column_text(stmt, 0));
			//const unsigned char* sent = sqlite3_column_text(stmt, 0);
		}
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

	cout << format("Usernames from {} are now in a vector.", dname.get_name()) << endl;

	return 0;
}
