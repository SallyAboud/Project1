#include "FileHandler.h"
#include<string>
#include "RecordManager.h" 
#include <fstream>
#include<iostream>
using namespace std;
void FileHandler::saveToFile() {
	string path = "d:\\Files\\Record";
	path += char(id+ 48);
	path += ".txt";
	ofstream project(path);
	project << "Name\t\t" << name
		<< "\nTask_duration\t" << taskDuration
		<< "\nAddress\t\t" << address
		<< "\nDate_and_time\t" << dateTime << "\n";
	project.close();
	cout << "The file is saved\n";
	cout << id << "\n" << path;

/*
	ofstream project("d:\\project.txt", std::ios_base::app);
	project << id << ".\nName\t\t" << name
		<< "\nTask_duration\t" << taskDuration
		<< "\nAddress\t\t" << address
		<< "\nDate_and_time\t" << dateTime << "\n"; 
	project.close();
	cout << "The file is saved\n";
	*/
}
void FileHandler::readFromFile() {
	string path = "d:\\Files\\Record";
	path += char(id + 48);
	path += ".txt";
	ifstream project(path);
	char x;
	while (!project.eof()) {
		project.get(x);
	}
	project.close();
}
void FileHandler::updateFile() {
	/*ifstream iproject("d:\\project.txt");
	ofstream oproject("d:\\oproject.txt");
	string str;
	vector<char>str;
	vector<string>str2;
	string str3;
	//int linesToRemove = 0;
	while (!iproject.eof()) {
		/*getline(iproject, str);
		for (int i = 0; i < str.size(); i++)
		{
			if (str.at(i) == ' ') {
				str2.push_back(str3);
				str3 = "";
			}
			else {
				str3 += str.at(i);
			}
		}
		if (str == name) {

			oproject << "Name\t\t" << name
				<< "\nTask_duration\t" << taskDuration
				<< "\nAddress\t\t" << address
				<< "\nDate_and_time\t" << dateTime << "\n";
			//linesToRemove = 3;
		}
		/*
		if (linesToRemove > 0) {
			linesToRemove--;
		}
		else {
			oproject << str << "\t" << str << "\n";
		}

	}
	oproject.close();
	iproject.close();
	cout << "The file is updated\n";*/
	/*ifstream iproject("d:\\project.txt");
	ofstream oproject("d:\\oproject.txt");
	char c;
	string str;
	int linesToRemove = 0;
	iproject.get(c);
	while (!iproject.eof()) {
		if (c==((char)(s+48))) {

			oproject << id << ".\nName\t\t" << name
				<< "\nTask_duration\t" << taskDuration
				<< "\nAddress\t\t" << address
				<< "\nDate_and_time\t" << dateTime << "\n";
			linesToRemove = 4;
		}
		if (linesToRemove > 0) {
			linesToRemove--;
		}
		else if(linesToRemove <= 0){
			iproject.get(c);
			oproject << c << ".\n";
			for (int i = 0; i < 4; i++) {
				getline(iproject, str);
				oproject << str << "\n";
			}
		}

	}
	oproject.close();
	iproject.close();
	cout << "The file is updated\n";*/
	saveToFile();
	}
void FileHandler::fileAdder(){

	ofstream projectAdder("d:\\Files\\Records.txt",std::ios_base::app);
	for (int i = 1; i <= s; i++) {
		string path = "d:\\Files\\Record";
		path += char(i + 48);
		path += ".txt";
		ifstream project(path);
		char x;
		while (!project.eof()) {
			project.get(x);
			projectAdder << x;
		}
		project.close();
	}
	projectAdder.close();

}
