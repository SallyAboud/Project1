#pragma once
#ifndef RecordManager_h
#define RecordManager_h
#include<string>
#include"PasswordManager.h"
using namespace std;
class RecordManager :public PasswordManager
{
protected:
	string taskDuration;
	string name;
	string address;
	string date;
	string time ;
	static int s;
	int id;
public:
	void addRecord();
	void viewRecord();
	void editRecord();
	void deleteRecord();
};
#endif
