#include "PasswordManager.h"
#include<iostream>
#include <string>
using namespace std;
void PasswordManager::setPassword(string newPassword) {
	password = newPassword;
}
string PasswordManager::getPassword() {
	return password;
}