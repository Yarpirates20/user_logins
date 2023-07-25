#pragma once
#include <string>
#include "DB.h"
#include <vector>
class User
{
private:
	std::string username;
	std::string hashed_password_input;
	std::vector<const unsigned char*> unameVec;

public:
	void set_username();
	std::string get_username();
	void input_password();
	std::string get_hash();
	int add_to_table(std::string, std::string, DB);
	int create_username_vector(std::string, DB);

};

