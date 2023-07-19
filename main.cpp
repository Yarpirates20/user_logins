#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>
#include "md5.h"
#include "sha256.h"
using namespace std;

typedef unordered_map<string, string> CredentialMap;

// Prototypes
bool is_valid_credentials(string, string, CredentialMap);


int main()
{
	/*string steveslist = "steveslist";
	cout << "md5 of 'steveslist': " << md5("steveslist") << endl;
	cout << "sha256('" << steveslist << "'):" << sha256(steveslist) << endl;*/
	//string pass = "password123";
	/*string defaultHash = sha256("password123");
	cout << defaultHash;
	cout << "\n\n";
	cout << "snuffles456: " << sha256("snuffles456");
	cout << "\n";
	cout << "0987654321: " << sha256("0987654321");
	cout << "\n";
	cout << "rsamo: " << sha256("rsamo");
	cout << "\n";*/

	CredentialMap logins =
	{
		{"robert", "ef92b778bafe771e89245b89ecbc08a44a4e166c06659911881f383d4473e94f"},
		{"anoosh", "3c32608fd9ffd87ae17dbb3a65a509cc8ba5aa395147c99ed20bdba9c434d8c2"},
		{"ajsam", "17756315ebd47b7110359fc7b168179bf6f2df3646fcc888bc8aa05c78b38ac1"},
		{"rsamo", "401704e81a7c596050636d02ad6f8c2ec0726d2ca1d2a2bb526c01c67c8a5506"}
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

	if (search != logins.end() && (search->second) == sha256(passwd))
	{
		return true;
	}

	return false;
}
