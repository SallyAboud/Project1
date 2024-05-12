#include "RecordManager.h"
#include<iostream>
#include<string>
#include"PasswordManager.h"
#include<stdlib.h>
#include<fstream>

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
	cout << "What is the date  (DD/MM/YYYY)?\n";
	getline(cin>>ws, date);
	cout << "What is the time (00:00 pm)?\n";
	getline(cin>>ws, time);
}
void RecordManager::viewRecord() {
	/*cout << "What is the password?\n";
	string pass;
	cin >> pass;
	if (pass == managerpass) {
		cout << "\n\tName\t\t" << name
			<< "\n\tTask duration\t" << taskDuration
			<< "\n\tAddress\t\t" << address
			<< "\n\tDate\t\t" << date << "\n"
			<< "\n\Time\t\t" << time << "\n";
	}*/
	cout << "What is the manager password?\n";
	string pass;
	cin >> pass;
	if (pass == managerpass) {
		string viewName;
		int d = 0;
		cout << "What is the name of the record you want to view?\n";
		getline(cin >> ws, viewName);
		for (int i = 1; i <= s; i++) {
			string path = "d:\\Files\\Record";
			path += char(i + 48);
			path += ".txt";
			ifstream project(path);
			string x, y;
			while (!project.eof()) {
				project >> y;
				getline(cin >> ws, x);
				if (viewName == x) {
					d = id;
					break;
				}
			}
			project.close();
		}
		if (d == 0) {
			cout << "There is no such a record name\nDo you still want to make a record to a record\n1.Yes\t\t\t2.No";
			int yn;
			cin >> yn;
			if (yn == 1) {
				editRecord();
			}

			else {
				cout << "incorrect password\n";
				viewRecord();
			}
		}
		else{
			string path = "d:\\Files\\Record";
			path += char(d + 48);
			path += ".txt";
			ifstream viewProject(path);
			char view;
			while (!viewProject.eof()) {
				viewProject.get(view);
				cout << view;
			}
			viewProject.close();
		}
		
	}

}
void RecordManager::editRecord() {
	cout << "What is the manager password?\n";
	string pass;
	cin >> pass;
	if (pass==managerpass ){
		string editName;
		int d = 0;
		cout << "What is the name of the record you want to edit?\n";
		cin >> editName;
		for (int i = 1; i <= s; i++) {
			string path = "d:\\Files\\Record";
			path += char(i + 48);
			path += ".txt";
			ifstream project(path);
			string x,y;
			while (!project.eof()) {
				project >> y;
				getline(cin >> ws, x);
				if (editName == x) {
					d = id;
					break;
				}
			}
			project.close();
		}
		if (d == 0) {
			cout << "There is no such a record name\nDo you still want to make an edit to a record\n1.Yes\t\t\t2.No";
			int yn;
			cin>>yn;
			if (yn == 1) {
				editRecord();
			}
			else if (yn != 2) {
				cout << "invaild number\n";
			}
		}
		cout << "Do you want to make changes to:\n1.Name\n2.Task Duration\n3.Address\n4.Date\n5.Time\n6.Quit\n";
		int a;
		cin >> a;
		while (a != 6) {
			switch (a) {
			case 1:
				cout << "What is your new name?\n";
				getline(cin >> ws, name);
				break;
			case 2:
				cout << "What is your  new task duration?\n"; 
				getline(cin >> ws, taskDuration);
				break;
			case 3:
				cout << "What is your new address?\n";
				getline(cin >> ws, address);
				break;
			case 4:
				cout << "What is the new date?   (DD/MM/YYYY)\n";
				getline(cin >> ws, date);
				break;
			case 5 :
				cout << "What is the new time?  00:00Pm\n";
				getline(cin >> ws, time);
			default:
				cout << "invalid number";
			}
			cout << "do you want to make any other changes to:\n1.Name\n2.Task Duration\n3.Address\n4.Date\n5.Time\n6.quit";
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
		date = "";
		time = "";
		id=0;
	}
	else {
		cout << "incorrect password\n";
		deleteRecord();
	}
}
