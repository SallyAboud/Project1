#pragma once
#ifndef FileHandler_h
#define FileHandler_h
#include<string>
#include "RecordManager.h" 
using namespace std;
class FileHandler :public RecordManager
{
public:
	void saveToFile();
	void readFromFile();
	void updateFile();
	void fileAdder();
};
#endif