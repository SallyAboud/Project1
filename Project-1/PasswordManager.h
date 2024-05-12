#pragma once
#ifndef PasswordManager_h
#define PasswordManager_h
#include<string>
using namespace std;
class PasswordManager
{
protected:
	string password;
	string managerpass = "SallyHaneen";
public:
	string getPassword();
	void setPassword(string newPassword);

};
#endif
