#pragma once
#include <string>
#include "DB.h"
class User
{
private:
	std::string username;
	std::string hashed_password_input;

public:
	void set_username();
	std::string get_username();
	void input_password();
	std::string get_hash();
	void add_to_table(std::string, std::string);

};

