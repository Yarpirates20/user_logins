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

    

    db_name = name.c_str();
}

std::string DB::get_name()
{
    return db_name;
}

int DB::create_database(string name)
{
    int rc = sqlite3_open(name.c_str(), &db);
    
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
