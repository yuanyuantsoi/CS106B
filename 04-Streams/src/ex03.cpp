/*
 * File: ex03.cpp
 * -------------------------------------
 *  This program prints the longest line in a file chosen by the user.
 *  If several lines are all equally long, your program should print
 *  the first such line.
 */

#include <string>
#include <iostream>
#include <fstream>
#include "simpio.h"
using namespace std;

string promptUserForFile(ifstream & infile, string prompt = "");

int main() {
	ifstream infile;
	promptUserForFile(infile, "Enter filename: ");
	string line;
        string longestLine = "";
	while (getline(infile, line)) {
		if (longestLine.length() < line.length()) longestLine = line;
	}
	infile.close();
	cout << longestLine << endl;
	return 0;
}

string promptUserForFile(ifstream & infile, string prompt) {
	while (true) {
		cout << prompt;
		string filename;
		getline(cin, filename);
		infile.open(filename.c_str());
		if (!infile.fail()) return filename;
		infile.clear();
		cout << "Unable to open that file. Try agagin." << endl;
		if (prompt == "") prompt = "Input file: ";
	}
}


