#include <iostream>
#include <string>
using namespace std;

// Prototypes
bool is_valid_credentials(string, string);


int main()
{
	string username, password;

	cout << "Enter username: ";
	cin >> username;

	cout << "Enter password: ";
	cin >> password;

	if (is_valid_credentials(username, password))
	{
		cout << "\u001b[2J";
		cout << "\nMy deepest, darkest secret is that I'm a potato.\n";
	}
	else
	{
		cout << "\u001b[2J";
		cout << "\nGet lost hacky-sack!\n";
	}


	return 0;
}

bool is_valid_credentials(string uname, string passwd)
{
	if (uname == "robert" && passwd == "password123")
	{
		return true;
	}

	return false;
}
