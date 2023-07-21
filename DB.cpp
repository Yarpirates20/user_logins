#include "DB.h"
#include <iostream>
#include <sqlite3.h>
#include <string>
using namespace std;

void DB::set_db_name()
{
    string name;
    cout << "Enter database name: ";
    getline(cin, name);
    
    string dir = "C:\\Users\\rsamo\\test\\";

    db_name = dir.append(name);
}

std::string DB::get_name()
{
    return db_name;
}

int DB::create_database()
{

    int rc = sqlite3_open(db_name.c_str(), &db);
    
    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
    }

    sqlite3_close(db);
}

int DB::create_table()
{
    string sql = "CREATE TABLE users("
        "USERNAME VARCHAR,"
        "PASSWORD_HASH VARCHAR);";

    int exit = 0;
    exit = sqlite3_open(db_name.c_str(), &db);

    char* messageError;
    exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        cerr << "Error Create Table " << endl;
        sqlite3_free(messageError);
    }
    else
    {
        cout << "Table created successfully" << endl;
    }

    sqlite3_close(db);
    return 0;
}
