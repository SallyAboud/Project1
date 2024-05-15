#include "Menu.h"
#include<string>
#include <iostream>
#include"RecordManager.h"
#include"PasswordManager.h"
#include"FileHandler.h"
#include <fstream>
using namespace std;
int num;
string newpass;
void Menu::displayMainMenu() {
	cout << "\t\tMain Menu\n1.Add Record\n2.View Record List\n"
		<<"3.Edit Record\n4.Delete Record\n5.Make New Password\n"
		<<"6.Display New Password\n7.Display Record List\n"
		<<"8.Quit\n" << endl;
	getUserChoice();

}
void Menu::displayRecordList() {
	cout << "What is the manager password?\n";
	string pass;
	string DisplayName;
	int d = 0;
	cin >> pass;
	if (pass == managerpass) {
		cout << "What is the name of the File you want to display?\n";
		getline(cin >> ws, DisplayName);
		for (int i = 1; i <= s; i++) {
			string path = "d:\\Files\\Record";
			path += char(i + 48);
			path += ".txt";
			ifstream project(path);
			string x, y;
			while (!project.eof()) {
				project >> y;
				getline(project >> ws, x);
				if (DisplayName == x) {
					d = i;
					break;
				}
			}
			project.close();
		}
		if (d == 0) {
			cout << "There is no such a record name\nDo you still want to display the record"
				<< "\n1.Yes\t\t\t2.No";
			int yn;
			cin >> yn;
			if (yn == 1) {
				displayRecordList();
			}
			else if (yn != 2) {
				cout << "Invaild number\n";
			}
		}
		else {
			string userPass;
			cout << "What is the user password?\n";
			cin >> userPass;
			if (userPass == passes.at(d - 1)) {
				string path = "d:\\Files\\Record";
				path += char(d + 48);
				path += ".txt";
				ifstream project(path);
				char x;
				while (!project.eof()) {
					project.get(x);
					cout << x;
				}
				project.close();
			}
			else {
				cout << "Incorrect Password";
			}

		}
	}
	else {
		cout << "Incorrect password";
		displayRecordList();
	}
		
}
void Menu::getUserChoice() {
	cin >> num;
	int x;
	string p="";
	string setPass;
	switch (num) {
	case 1:
		cout << "What is the password manager?\n";
		cin >> p;
		while (p != managerpass) {
			cout << "incorrect password";
			cout << "What is the password manager?\n";
			cin >> p;
		}
		addRecord();
		cout << "What is the Password you want to set?\n";
		getline(cin >> ws, setPass);
		setPassword(setPass);
		saveToFile();
		system("cls");
		
		break;
	case 2:
		viewRecord();
		cout << "if you want to clear the screen enter 0 " << endl;
		cin >> x;
		if (x == 0) {
			system("cls");
		}
		break;
	case 3:
		editRecord();
		system("cls");
		break;
	case 4:
		deleteRecord();
		updateFile();
		//system("cls");
		break;
	case 5:
		cout << "What is the password manager?\n";
		cin >> p;
		while (p != managerpass) {
			cout << "Incorrect password";
			cout << "What is the password manager?\n";
			cin >> p;
		}
		cout << "Enter the new password " << endl;
		getline(cin >> ws, newpass);
		setPassword(newpass);
		system("cls");
		break;
	case 6:
		cout << "What is the password manager?\n";
		cin >> p;
		while(p != managerpass){
			cout << "Incorrect password\n";
			cout << "What is the password manager?\n";
			cin >> p;
		} 
		cout << "The password is:\n" << getPassword() << "\n";
		cout << "if you want to clear the screen enter 0 " << endl;
		cin >> x;
		if (x == 0) {
			system("cls");
		}
		break;
	case 7: 
		displayRecordList();
		cout<<"if you want to clear the screen enter 0 "<<endl;
		cin>>x ;
		if(x==0){
			system("cls");
		}
		break;
	case 8:
		cout << "quit main menu";
		fileAdder();
		break;
	default:
		cout << "Invalid Number ";
	}
	while (num != 8) {
		displayMainMenu();
	}
}
