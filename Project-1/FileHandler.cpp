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
