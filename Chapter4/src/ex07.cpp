/*
 * File: ex07.cpp
 * --------------------------------------
 *  This program reads characters from an input file and displays them
 *  on the console after makeing random substitutions.
 *  The rule for substitution:
 *  	1. replace uppercase(lowercase)  char with a uppercase(lowercase) char
 *  	2. nonalphabetic char remaines unchanged
 */

#include <iostream>
#include <fstream>
#include <cctype>
#include "simpio.h"
#include "random.h"
#include "filelib.h"
using namespace std;

char subCharacter(char ch);

int main() {
	ifstream infile;
	promptUserForFile(infile, "Input file: ");
	string line = "";
	while (getline(infile, line)) {
		for (int i = 0; i < line.length(); i++) {
			cout << subCharacter(line[i]);
		}
		cout << endl;
	}
	return 0;
}

char subCharacter(char ch) {
	if (!isalpha(ch)) return ch;
	if (isupper(ch)) return 'A' + randomInteger(0, 25);
	if (islower(ch)) return 'a' + randomInteger(0, 25);
}
