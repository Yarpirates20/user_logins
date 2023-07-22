#pragma once
#include "sha256.h"
#include <sqlite3.h>
#include <string>

class DB
{
private:
	std::string db_name;
	sqlite3 *db;
	const char* data = "Callback function called";
	char* z_Err_Msg = 0;

public:
	DB() = default;
	void set_db_name();
	std::string get_name();
	int create_database();
	int create_table();
	bool db_exists();
	static int callback(void* data, int argc, char** argv, char** azColName);
	int table_exists();
};

