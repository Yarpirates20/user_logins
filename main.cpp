#include <iostream>
//#include <iomanip>
//#include <unordered_map>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include <stdio.h>
#include <sqlite3.h>
//#include "md5.h"
#include "sha256.h"
#include "DB.h"
#include "User.h"
using namespace std;
using json = nlohmann::json;

//typedef unordered_map<string, string> CredentialMap;

// Prototypes
bool is_valid_credentials(string, string);


int main(int argc, char* argv[])
{
	// Create db and table
	//DB d_base;
	//d_base.set_db_name();

	//string db_name = d_base.get_name();
	//char overwrite;

	//if (d_base.db_exists())
	//{

	//	cout << db_name << " is all ready an existing database.\n\n";

	//	//d_base.table_exists();

	//	cout << "\n\n**Overwrite existing database? **\n"
	//		<< "WARNING: ALL INFORMATION WILL BE LOST (Y/N): ";
	//	cin >> overwrite;

	//	if (tolower(overwrite) == 'n')
	//	{
	//		cout << "\nExiting program.\n";
	//		exit(1);
	//	}
	//}
	//else
	//{
	//	cout << db_name << " does not yet exist!\n";
	//}

	//if ((d_base.db_exists() && tolower(overwrite) == 'y') || !(d_base.db_exists()))
	//{

	//d_base.create_database();
	//cout << "Database created at " << db_name << endl;

	//d_base.create_table();
	//}

	// Create user
	/*User user;

	cin.ignore();
	user.set_username();

	string uname = user.get_username();

	user.input_password();

	string pwd = user.get_hash();

	user.add_to_table(uname, pwd, d_base);


	d_base.table_exists();*/

	//// ##### DEBUG COMMENT OUT ##### 
	

	//// Get user inputs 
	string username, password;

	cout << "Enter username: ";
	cin >> username;

	cout << "Enter password: ";
	cin >> password;

	if (is_valid_credentials(username, password))
	{
		cout << "\u001b[2J";
		cout << "\nMy deepest, darkest secret is that I'm a potato.\n";
	}
	else
	{
		cout << "\u001b[2J";
		cout << "\nGet lost hacky-sack!\n";
	}


	return 0;
}

bool is_valid_credentials(string username, string passwd)
{
	

	passwd = sha256(passwd);
	//ifstream infile("logins.json");
	//json data = json::parse(infile);
	ifstream infile({ R"(C:\Users\rsamo\source\config_files\db.json)"s });
	json data = json::parse(infile);
	string dbName = data["name"];
	string dbFile = data["DefaultDbPath"];
	dbFile = dbFile.append(dbName);

	//TODO: query database to see if user exists and if password_hash matches
	sqlite3* db;
	int rc;
	sqlite3_stmt* stmt;
	string sql = "SELECT * FROM users;";
	/*string::size_type n = sql.length();*/

	rc = sqlite3_open(dbFile.c_str(), &db);
	if (rc)
	{
		fprintf(stderr, "\nCan't open database: %s\n", sqlite3_errmsg(db));
		return (0);
	}
	else
	{
		fprintf(stderr, "\nOpened database successfully\n");
	}

	//Prepared statement
	//string size_type nsql = sql.lenth();
	rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &stmt, nullptr);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else
	{
		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
		{
			string columnName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
			string columnPwd = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			if (columnName == username && columnPwd == passwd)
			{
				return true;
			}
		}
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

	//if (data.count(uname) != 0 && data.at(uname) == passwd)
	//{
	//	return true;
	//}
	


	return false;
}
