/*
 * Function: AirportCodes.cpp
 * -----------------------------
 *  This program looks up a three-letter airport code in a Map object.
 */

#include <iostream>
#include <fstream>
#include "error.h"
#include <string>
#include "map.h"
#include "strlib.h"
using namespace std;

/* Function prototypes */

void readCodeFile(string filename, Map<string, string> & map);

/* Main program */

int main() {
	Map<string, string> airportCodes;
	readCodeFile("AirportCodes.txt", airportCodes);
	while (true) {
		string line;
		cout << "Airport code: ";
		getline(cin, line);
		if (line == "") break;
		string code = toUpperCase(line);
		if (airportCodes.containsKey(code)) {
			cout << code << " is in " << airportCodes.get(code) << endl;
		} else {
			cout << "There is no such airport code" << endl;
		}
	}
	return 0;
}

void readCodeFile(string filename, Map<string, string> & map) {
	ifstream infile;
	infile.open(filename.c_str());
	if (infile.fail()) error("Can't read the data file");
	string line;
	while (getline(infile, line)) {
		if (line.length() < 4 || line[3] != '=') {
			error("Illegal data line: " + line);
		}
		string code = toUpperCase(line.substr(0,3));
		map.put(code, line.substr(4));
	}
	infile.close();
}
