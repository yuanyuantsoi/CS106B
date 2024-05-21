/*
 * File: ex11.cpp
 * ------------------------
 *  This program implements the function
 *  stringToReal and realToString.
 */

#include <iostream>
#include <string>
#include <sstream>
#include "simpio.h"
using namespace std;

double stringToReal(string str);
string realToString(double num);

int main() {
	string str = getLine("Enter string: ");
	double num = stringToReal(str);
	cout << num << endl;

	cout << realToString(num) << endl;
	return 0;
}

double stringToReal(string str) {
	double num;
	istringstream stream(str);
	stream >> num >> ws;
	if (stream.fail() || !stream.eof()) {
		cout << "Illegal integer format" << endl;
	}
	return num;
}

string realToString(double num) {
	ostringstream stream;
	stream << num;
	return stream.str();
}

