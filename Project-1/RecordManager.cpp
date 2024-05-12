#include "RecordManager.h"
#include<iostream>
#include<string>
#include"PasswordManager.h"
#include<stdlib.h>

using namespace std;
int RecordManager::s = 0;
void RecordManager::addRecord() {
	s += 1;
	id = s;
	//system("cls");
	cout << "What is your name?\n";
	getline(cin>>ws, name);
	cout << "What is your task duration?\n";
	getline(cin>>ws, taskDuration);
	cout << "What is your address?\n";
	getline(cin>>ws, address);
	cout << "What is the date and time?\n";
	getline(cin>>ws, dateTime);

	system("CLS");
}
void RecordManager::viewRecord() {
	system("cls");
	/*cout << "What is the password?\n";
	string pass;
	getline(cin, pass);
	if (pass == getPassword()) {*/
		cout << "\n\tName\t\t" << name
			<< "\n\tTask_duration\t" << taskDuration
			<< "\n\tAddress\t\t" << address
			<< "\n\tDate_and_time\t" << dateTime << "\n";
	//}
	/*else {
		cout << "incorrect password\n";
		viewRecord();
	}*/
}
void RecordManager::editRecord() {
	//cout << "What is the password?\n";
	//string pass;
	//cin >> pass;
	//if (pass==getPassword() ){
		cout << "Do you want to make changes to:\n1.Name\n2.Task Duration\n3.Address\n4.Date and Time\n5.Quit\n";
		int a;
		cin >> a;
		while (a != 5) {
			switch (a) {
			case 1:
				cin.ignore();
				cout << "What is your new name?\n";
				getline(cin, name);
				break;
			case 2:
				cin.ignore();
				cout << "What is your  new task duration?\n"; 
				cin >> taskDuration;
				break;
			case 3:
				cin.ignore();
				cout << "What is your new address?\n";
				cin>> address;
				break;
			case 4:
				cin.ignore();
				cout << "What is the new date and time?\n";
				cin>> dateTime;
				break;
			default:
				cout << "invalid number";
			}
			cout << "do you want to make any other changes to:\n1.Name\n2.Task Duration\n3.Address\n4.Date and Time\n5.quit";
			cin >> a;
		}
		system("CLS");
	/* }
	else {
		cout << "incorrect password\n";
		editRecord();
	}*/
}
void RecordManager::deleteRecord() {
	cout << "What is the password?\n";
	string pass;
	cin >> pass;
	if (pass == getPassword()) {
		name = "";
		taskDuration = "";
		address = "";
		dateTime = "";
		system("CLS");
	}
	else {
		cout << "incorrect password\n";
		deleteRecord();
	}
}