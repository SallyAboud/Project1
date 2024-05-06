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
	string dateTime;
	static int s;
public:
	void addRecord();
	void viewRecord();
	void editRecord();
	void deleteRecord();
};
#endif // !1