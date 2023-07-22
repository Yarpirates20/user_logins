#pragma once
#include <string>
class User
{
private:
	std::string username;
	std::string passwordInput;

public:
	void set_username();
	std::string get_username();
	void input_password();
	void hash_password(std::string);
	std::string get_hash();
	void add_to_table(std::string, std::string);

};

