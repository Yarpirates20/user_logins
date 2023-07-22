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
using namespace std;
using json = nlohmann::json;

//typedef unordered_map<string, string> CredentialMap;

// Prototypes
bool is_valid_credentials(string, string);


int main(int argc, char* argv[])
{
	DB d_base;
	d_base.set_db_name();

	string db_name = d_base.get_name();
	char overwrite;

	if (d_base.db_exists())
	{

		cout << db_name << " is all ready an existing database.\n\n";

		d_base.table_exists();

		cout << "\n\n**Overwrite existing database? **\n"
			<< "WARNING: ALL INFORMATION WILL BE LOST (Y/N): ";
		cin >> overwrite;

		if (tolower(overwrite) == 'n')
		{
			cout << "\nExiting program.\n";
			exit(1);
		}
	}
	else
	{
		cout << db_name << " does not yet exist!\n";
	}

	if ((d_base.db_exists() && tolower(overwrite) == 'y') || !(d_base.db_exists()))
	{

	d_base.create_database();
	cout << "Database created at " << db_name << endl;

	d_base.create_table();
	}



	string username, password;

	// ##### DEBUG COMMENT OUT ##### 
	// Get user inputs 
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

bool is_valid_credentials(string uname, string passwd)
{
	passwd = sha256(passwd);
	ifstream infile("logins.json");
	json data = json::parse(infile);

	

	if (data.count(uname) != 0 && data.at(uname) == passwd)
	{
		return true;
	}
	


	return false;
}
