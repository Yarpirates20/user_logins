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
        return(1);
    }
}
