#include "FileHandler.h"
#include<string>
#include "RecordManager.h" 
#include <fstream>
#include<iostream>
using namespace std;

void FileHandler::saveToFile() {
	ofstream project("d:\\project.txt", std::ios_base::app);
	project << "Name\t\t" << name
		<< "\nTask Duration\t" << taskDuration
		<< "\nAddress\t\t" << address
		<< "\nDate and Time\t" << dateTime << "\n";
	project.close();
	cout << "The file is saved\n";
}
void FileHandler::readFromFile() {
	ifstream project("d:\\project1.txt");
	char x;
	while (!project.eof()) {
		project.get(x);
	}
	project.close();
}
void FileHandler::updateFile() {

	ifstream iproject("d:\\project.txt");
	ofstream oproject("d:\\oproject.txt");
	string str;
	while (!iproject.eof()) {
		iproject >> str;
		if (str == name) {

			oproject << "Name\t\t" << name
				<< "\nTask Duration\t" << taskDuration
				<< "\nAddress\t\t" << address
				<< "\nDate and Time\t" << dateTime << "\n";
		}
		else {
			oproject << str << "\t";
		}

	}
	oproject.close();
	iproject.close();
	cout << "The file is saved\n";
}