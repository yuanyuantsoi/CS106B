/*
 * File: ex05.cpp
 * -----------------------------------
 *  This program implements the getRoot and getExtension
 *  fucntion.
 */

#include <fstream>
#include <string>
#include <iostream>
#include "simpio.h"
using namespace std;

string getRoot(string filename);
string getExtension(string filename);

int main() {
	string filename = getLine("Enter filename: ");
	string root = getRoot(filename);
	string extension = getExtension(filename);
	cout << root << endl;
	cout << extension << endl;
	return 0;
}

string getRoot(string filename) {
	int dot = filename.find('.', 0);
	if (dot == string::npos) return filename;
	return filename.substr(0, dot);
}

string getExtension(string filename) {
	int dot = filename.find('.', 0);
	if (dot == string::npos) return "";
	return filename.substr(dot);
}
