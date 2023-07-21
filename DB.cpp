#include "DB.h"
#include <iostream>
using namespace std;

void DB::set_db_name()
{
    string name;
    cout << "Enter database name: ";
    getline(cin, name);

    db_name = name;
}

std::string DB::get_name()
{
    return db_name;
}
