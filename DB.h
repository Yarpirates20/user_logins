#pragma once
#include "sha256.h"
#include <sqlite3.h>
#include <string>

class DB
{
private:
	const char* db_name;
	sqlite3 *db;

public:
	DB() = default;
	void set_db_name();
	std::string get_name();
	int create_database(std::string);
};

