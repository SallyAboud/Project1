#pragma once
#ifndef PasswordManager_h
#define PasswordManager_h
#include<string>
#include<vector>
using namespace std;
class PasswordManager
{
protected:
	string password;
	string managerpass = "SallyHaneen";
	vector<string> passes;
public:
	string getPassword();
	void setPassword(string newPassword);

};
#endif
