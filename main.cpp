#include <iostream>
#include <unordered_map>
#include <string>
// TODO: Remember to do something here
using namespace std;

typedef unordered_map<string, string> CredentialMap;
// Prototypes
bool is_valid_credentials(string, string, CredentialMap);


int main()
{
	CredentialMap logins =
	{
		{"robert", "password123"},
		{"anoosh", "snuffles456"},
		{"ajsam", "0987654321"},
		{"rsamo", "rsamo"}
	};

	string username, password;

	cout << "Enter username: ";
	cin >> username;

	cout << "Enter password: ";
	cin >> password;

	if (is_valid_credentials(username, password, logins))
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

bool is_valid_credentials(string uname, string passwd, CredentialMap logins)
{
	// Create iterator
	/*unordered_map<string, string>::iterator it;

	it = logins.find(uname);*/
	auto search = logins.find(uname);

	if (search != logins.end() && search->second == passwd)
	{
		return true;
	}

	return false;
}
