/*
 * File: ex08.cpp
 * ------------------------------------
 *  This program implements a function removeComments
 *  that copies char from inpu stream to output stream.
 *  The function should recognize both comment conventions:
 *  	1. any text begining with "/*" and ending with "\*\/"
 *  	2. any test begining with //
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "filelib.h"
using namespace std;

void removeComments(istream & is, ostream & os);
string removeCmtInLine(string line, bool & multiLineCmt);

int main() {
	ifstream infile;
	promptUserForFile(infile, "Input file: ");
	removeComments(infile, cout);
	infile.close();
	return 0;
}

void removeComments(istream & is, ostream & os) {
	string line;
	bool inComment = false;
	char prevChar = '\0'; // The null character
	while (getline(is, line)) {
		for (int i = 0; i < line.length(); i++) {
			if (!inComment) {
				if (line[i] == '/' && prevChar == '/') {
					break;
				}else if (line[i] == '*' && prevChar == '/') {
					inComment = true;
					os << ' ';
				}else {
					os << line[i];
				}
			}else {
				if (line[i] == '/' && prevChar == '*') {
					inComment = false;
					os.put(' ');
				}
			}
			prevChar = line[i];
		}
		if (!inComment) {
			os << '\n';
			prevChar = '\0';
		}
	}
	return;
}
