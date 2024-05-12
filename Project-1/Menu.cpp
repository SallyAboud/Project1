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
	string pass;
	if(pass==getPassword()){
	cout << "\n\tName\t\t" << name
	<< "\n\tTask_duration\t" << taskDuration
	<< "\n\tAddress\t\t" << address
	<< "\n\tDate\t" << date 
	<< "\n\ttime\t" << time << "\n";
	}
	else {
		cout<<"Incorrect password"<<endl;
		displayRecordList();
	}
		
}
void Menu::getUserChoice() {
	cin >> num;
	int x;
	string p="";
	switch (num) {
	case 1:
		addRecord();
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
		updateFile();
		system("cls");
		break;
	case 4:
		deleteRecord();
		updateFile();
		system("cls");
		break;
	case 5:
		cout << "Enter the new password " << endl;
		cin.ignore();
		getline(cin,newpass);
		setPassword(newpass);
		system("cls");
		break;
	case 6:
		cout << "What is the password manager?\n";
		cin >> p;
		while(p != managerpass){
			cout << "incorrect password";
			cout << "What is the password manager?\n";
			cin >> p;
		} 
		cout << getPassword() << "\n";
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
		displayRecordList();
		cout<<"if you want to clear the screen enter 0 "<<endl;
		cin>>x ;
		if(x==0){
			system("cls");
		}
	case 11:
		cout << "quit main menu";
		fileAdder();
		break;
	default:
		cout << "Invalid Number ";
	}
	while (num != 11) {
		displayMainMenu();
	}
}
