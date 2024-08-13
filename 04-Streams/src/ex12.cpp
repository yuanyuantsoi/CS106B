/*
 * File: ex12.cpp
 * -------------------------------------
 *  This program implements the function
 *  getReal and getLine from simpio.h
 */

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

double getReal(string prompts);
string getLine(string prompts);

int main() {
	double num = getReal("Enter real num: ");
	string str = getLine("Enter str: ");

	cout << num << endl;
	cout << str << endl;

	return 0;
}

double getReal(string prompts) {
	string line;
	double value;
	while (true) {
		cout << prompts;
		getline(cin, line);
		istringstream stream(line);
		stream >> value >> ws;
		if (!stream.fail() || stream.eof()) break;
		cout << "Illegal format, please try again." << endl;
		if (prompts == "") prompts = "Enter real number: ";
	}
	return value;
}


string getLine(string prompts) {
	cout << prompts;
	string line;
	getline(cin, line);
	return line;
}
