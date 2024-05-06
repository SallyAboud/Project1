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
	cout << "\t\tMain Menu\n1.Add Record\n2.View Record\n3.Edit Record\n4.Delete Record\n5.Make New Password\n6.Display New Password\n7.Save Record To File\n8.Read Record From File\n9.Update File\n10.Quit\n" << endl;
	getUserChoice();

}
void Menu::displayRecordList() {
	ifstream project("project.txt");
	char x;
	while (!project.eof()) {
		project.get(x);
		cout << x;
	}
	project.close();
}
void Menu::getUserChoice() {
	cin >> num;
	system("CLS");
	switch (num) {
	case 1:
		addRecord();
		saveToFile();
		break;
	case 2:
		viewRecord();
		break;
	case 3:
		editRecord();
		updateFile();
		break;
	case 4:
		deleteRecord();
		updateFile();
		break;
	case 5:
		cout << "Enter the new password " << endl;
		cin >> newpass;
		setPassword(newpass);
		break;
	case 6:
		getPassword();
		break;
	case 7:
		saveToFile();
		break;
	case 8:
		readFromFile();
		break;
	case 9:
		updateFile();
		break;
	case 10:
		cout << "quit main menu";
		break;
	default:
		cout << "Invalid Number ";
	}
	while (num != 10) {
		displayMainMenu();
	}
}