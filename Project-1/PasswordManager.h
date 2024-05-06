#pragma once
#ifndef PasswordManager_h
#define PasswordManager_h
#include<string>
using namespace std;
class PasswordManager
{
	string password;
public:
	string getPassword();
	void setPassword(string newPassword);

};
#endif PasswordManager