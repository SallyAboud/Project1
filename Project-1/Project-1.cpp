#include "Menu.h"
#include<string>
#include"RecordManager.h"
#include"PasswordManager.h"
#include"FileHandler.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	Menu a,b,c,d,e,f;
	a.displayMainMenu();
	b.addRecord();
	b.saveToFile();
	c.addRecord();
	c.saveToFile();
	d.addRecord();
	d.saveToFile();
	e.addRecord();
	e.saveToFile();
	f.addRecord();
	f.saveToFile();
	f.fileAdder();
}