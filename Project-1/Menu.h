#pragma once
#ifndef Menu_h
#define Menu_h
#include<string>
#include"RecordManager.h"
#include"PasswordManager.h"
#include"FileHandler.h"
using namespace std;
class Menu :public FileHandler
{
public:
	void displayMainMenu();
	void displayRecordList();
	void getUserChoice();
};
#endif