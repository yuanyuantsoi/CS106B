/*
 * File: ex20.cpp
 * ----------------
 *  This program read AreaCodes.txt into a Map<int, string>, the main
 *  program asks the user for an area code and then looks for the corresponding 
 *  location.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "map.h"
#include "simpio.h"
#include "error.h"
#include "strlib.h"
using namespace std;

void readCodeFile(string filename, Map<int, string> & areacode);

int main() {
	Map<int, string> areacode;
	readCodeFile("AreaCodes.txt", areacode);
	while (true) {
		string line = getLine("Enter area code or state name: ");
		if (line.empty()) break;
		if (isdigit(line[0])) {
			cout << areacode[stringToInteger(line)] << endl;
		} else {
			for (int code : areacode) {
				if (areacode[code] == line) cout << code << endl;
			}
		}
	}

	return 0;
}

void readCodeFile(string filename, Map<int, string> & areacode) {
	ifstream infile;
	infile.open(filename.c_str());
	if (infile.fail()) error("Can't open file, please try again.");
	string line;
	while (getline(infile, line)) {
		if ((line.length() < 4) || (line[3] != '-')) 
		       error("Illegal data line: " + line);
		int code = stringToInteger(line.substr(0, 3));
		string location = line.substr(4);
		areacode.put(code, location);
	}
	return;
}	
