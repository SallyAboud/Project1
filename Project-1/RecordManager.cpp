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
	cout << "What is the time (00:00 Pm/Am)?\n";
	getline(cin>>ws, time);
	
}
void RecordManager::viewRecord() {
	cout << "What is the manager password?\n";
	string pass;
	cin >> pass;
	if (pass == managerpass) {
		cout << "\tThe List of the Records\n";
		for (int i = 1; i <= s; i++) {
			string path = "d:\\Files\\Record";
			path += char(i + 48);
			path += ".txt";
			ifstream project(path);
			char x;
			while (!project.eof()) {
				project.get(x);
				cout << x;
			}
			project.close();
		}
	}
	else {
		cout << "Incorrect password\n";
		viewRecord();
	}
}
void RecordManager::editRecord() {
	cout << "What is the manager password?\n";
	string pass;
	cin >> pass;
	if (pass == managerpass) {
		string EditName;
		int d = 0;
		cout << "What is the name of the record you want to edit?\n";
		cin >> EditName;
		for (int i = 1; i <= s; i++) {
			string path = "d:\\Files\\Record";
			path += char(i + 48);
			path += ".txt";
			ifstream project(path);
			string x, y;
			while (!project.eof()) {
				project >> y;
				getline(project >> ws, x);
				if (EditName == x) {
					d = i;
					break;
				}
			}
			project.close();
		}
		if (d == 0) {
			cout << "There is no such a record name\nDo you still want to make an edit to a record"
				<<"\n1.Yes\t\t\t2.No";
			int yn;
			cin >> yn;
			if (yn == 1) {
				editRecord();
			}
			else if (yn != 2) {
				cout << "invaild number\n";
			}
		}
		cout << "Do you want to make changes to:\n1.Name\n2.Task Duration"
			<<"\n3.Address\n4.Date\n5.Time\n6.Quit\n";
		int a;
		string editName, editTaskDuration, editAddress, editDate, editTime;
		cin >> a;
		string read, readWords;
		string pathEdit = "d:\\Files\\Record";
		pathEdit += char(d + 48);
		pathEdit += ".txt";
		char x;
		while (a != 6) {
			ifstream editProject(pathEdit);
			ofstream temp("d:\\Files\\TempRecord.txt");
			ofstream projectEdited;
			ifstream tempFile;
			switch (a) {
			case 1:
				cout << "What is your new name?\n";
				getline(cin >> ws, editName);
				while (!editProject.eof()) {
					editProject >> read;
					getline(editProject >> ws, readWords);
					if (read == "Name") {
						temp << read << "\t\t";
						temp << editName << "\n";
					}
					else if (read == "Task") {
						temp << read << " ";
						temp << readWords << "\n";
					}
					else {
						temp << read << "\t\t";
						temp << readWords << "\n";
					}
				}
				temp.close();
				editProject.close();
				projectEdited.open(pathEdit);
				tempFile.open("d:\\Files\\TempRecord.txt");
				x = '\0';
				
				while (!tempFile.eof()) {
					tempFile.get(x);
					projectEdited << x;
				}
				tempFile.close();
				projectEdited.close();

				break;
			case 2:
				cout << "What is your  new task duration?\n";
				getline(cin >> ws, editTaskDuration);

				while (!editProject.eof()) {
					editProject >> read;
					getline(editProject >> ws, readWords);
					if (read == "Task") {
						temp << read << " duration\t";
						temp << editTaskDuration << "\n";
					}
					else {
						temp << read << "\t\t";
						temp << readWords << "\n";
					}
				}
				temp.close();
				editProject.close();
				projectEdited.open(pathEdit);
				tempFile.open("d:\\Files\\TempRecord.txt");
				x = '\0';
				while (!tempFile.eof()) {
					tempFile.get(x);
					projectEdited << x;
				}
				tempFile.close();
				projectEdited.close();



				break;
			case 3:
				cout << "What is your new address?\n";
				getline(cin >> ws, editAddress);
				while (!editProject.eof()) {
					editProject >> read;
					getline(editProject >> ws, readWords);
					if (read == "Address") {
						temp << read << "\t\t";
						temp << editAddress << "\n";
					}
					else if (read == "Task") {
						temp << read << " ";
						temp << readWords << "\n";
					}
					else {
						temp << read << "\t\t";
						temp << readWords << "\n";
					}
				}
				temp.close();
				editProject.close();
				projectEdited.open(pathEdit);
				tempFile.open("d:\\Files\\TempRecord.txt");
				x = '\0';
				while (!tempFile.eof()) {
					tempFile.get(x);
					projectEdited << x;
				}
				tempFile.close();
				projectEdited.close();
				break;
			case 4:
				cout << "What is the new date?   (DD/MM/YYYY)\n";
				getline(cin >> ws, editDate);
				while (!editProject.eof()) {
					editProject >> read;
					getline(editProject >> ws, readWords);
					if (read == "Date") {
						temp << read << "\t\t";
						temp << editDate << "\n";
					}
					else if (read == "Task") {
						temp << read << " ";
						temp << readWords << "\n";
					}
					else {
						temp << read << "\t\t";
						temp << readWords << "\n";
					}
				}
				temp.close();
				editProject.close();
				projectEdited.open(pathEdit);
				tempFile.open("d:\\Files\\TempRecord.txt");
				x = '\0';
				while (!tempFile.eof()) {
					tempFile.get(x);
					projectEdited << x;
				}
				tempFile.close();
				projectEdited.close();

				break;
			case 5:
				cout << "What is the new time?  00:00Pm\n";
				getline(cin >> ws, editTime);
				while (!editProject.eof()) {
					editProject >> read;
					getline(editProject >> ws, readWords);
					if (read == "Time") {
						temp << read << "\t\t";
						temp << editTime << "\n";
					}
					else if (read == "Task") {
						temp << read << " ";
						temp << readWords << "\n";
					}
					else {
						temp << read << "\t\t";
						temp << readWords << "\n";
					}
				}
				temp.close();
				editProject.close();
				projectEdited.open(pathEdit);
				tempFile.open("d:\\Files\\TempRecord.txt");
				x = '\0';
				while (!tempFile.eof()) {
					tempFile.get(x);
					projectEdited << x;
				}
				tempFile.close();
				projectEdited.close();
				break;
			default:
				cout << "invalid number";
			}
			cout << "do you want to make any other changes to:\n1.Name\n2.Task Duration\n3.Address\n4.Date\n5.Time\n6.quit";
			cin >> a;
		}
	}
	else {
		cout << "Incorrect password\n";
		editRecord();
	}
}
void RecordManager::deleteRecord() {
	cout << "What is the manager password?\n";
	string pass;
	string DeleteName;
	int d = 0;
	cin >> pass;
	if (pass == managerpass) {
		cout << "What is the name of the File you want to delete?\n";
		getline(cin >> ws, DeleteName);
		for (int i = 1; i <= s; i++) {
			string path = "d:\\Files\\Record";
			path += char(i + 48);
			path += ".txt";
			ifstream project(path);
			string x, y;
			while (!project.eof()) {
				project >> y;
				getline(project >> ws, x);
				if (DeleteName == x) {
					d = i;
					break;
				}
			}
			project.close();
		}
		if (d == 0) {
			cout << "There is no such a record name\nDo you still want to make an edit to a record"
				<< "\n1.Yes\t\t\t2.No";
			int yn;
			cin >> yn;
			if (yn == 1) {
				editRecord();
			}
			else if (yn != 2) {
				cout << "Invaild number\n";
			}
		}
		else {
			string deletepath = "d:\\Files\\Record";
			deletepath += char(d + 48);
			deletepath += ".txt";
			ofstream project(deletepath);
			project << "";
			project.close();
		}
	}
	else {
		cout << "Incorrect password\n";
		deleteRecord();
	}
}
