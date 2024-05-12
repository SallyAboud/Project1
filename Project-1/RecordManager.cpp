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
	cout << "What is your name?\n";
	getline(cin>>ws, name);
	cout << "What is your task duration?\n";
	getline(cin>>ws, taskDuration);
	cout << "What is your address?\n";
	getline(cin>>ws, address);
	cout << "What is the date  (dd/mm/yyyy)?\n";
	getline(cin>>ws, date);
	cout << "What is the time (00:00 pm)?\n";
	getline(cin>>ws, time);
}
void RecordManager::viewRecord() {
	cout << "What is the password?\n";
	string pass;
	getline(cin, pass);
	if (pass == managerpass) {
		cout << "\n\tName\t\t" << name
			<< "\n\tTask duration\t" << taskDuration
			<< "\n\tAddress\t\t" << address
			<< "\n\tDate\t" << date << "\n"<< "\n\Time\t" << time << "\n";
	}
	else {
		cout << "incorrect password\n";
		viewRecord();
	}
}
void RecordManager::editRecord() {
	cout << "What is the manager password?\n";
	string pass;
	cin >> pass;
	if (pass==managerpass ){
		cout << "Do you want to make changes to:\n1.Name\n2.Task Duration\n3.Address\n4.Date\n5.Time\n6.Quit\n";
		int a;
		cin >> a;
		while (a != 6) {
			switch (a) {
			case 1:
				cout << "What is your new name?\n";
				getline(cin, name);
				break;
			case 2:
				cout << "What is your  new task duration?\n"; 
				cin >> taskDuration;
				break;
			case 3:
				cout << "What is your new address?\n";
				cin>> address;
				break;
			case 4:
				cout << "What is the new date and time?\n";
				cin>> date;
				break;
			case 5 :
				cout << "What is the new time?\n";
				cin>> time;
			default:
				cout << "invalid number";
			}
			cout << "do you want to make any other changes to:\n1.Name\n2.Task Duration\n3.Address\n4.Date and Time\n5.quit";
			cin >> a;
		}
	 }
	else {
		cout << "incorrect password\n";
		editRecord();
	}
}
void RecordManager::deleteRecord() {
	cout << "What is the password?\n";
	string pass;
	cin >> pass;
	if (pass == managerpass) {
		name = "";
		taskDuration = "";
		address = "";
		dateTime = "";
		id=0;
	}
	else {
		cout << "incorrect password\n";
		deleteRecord();
	}
}
