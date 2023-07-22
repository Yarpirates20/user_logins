#include "User.h"
#include <iostream>
#include <string>
#include "sha256.h"
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
