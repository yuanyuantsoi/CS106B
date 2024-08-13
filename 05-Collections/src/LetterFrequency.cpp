/*
 * File: LetterFrequency.cpp
 * ---------------------------
 *  This program counts the frequency of letters in a data file.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include "filelib.h"
#include "vector.h"
using namespace std;

/* Constants */

static const int COLUMNS = 7;

/* Main program */

int main() {
	ifstream infile;
	Vector<int> letterCounts(26);
	promptUserForFile(infile, "Input file: ");
	char ch;
	while (infile.get(ch)) {
		if (isalpha(ch)) {
			letterCounts[toupper(ch) - 'A']++;
		}
	}
	infile.close();
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		cout << setw(COLUMNS) << letterCounts[ch - 'A'] << " " << ch << endl;
	}
	return 0;
}
