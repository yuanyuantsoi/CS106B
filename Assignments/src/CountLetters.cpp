/*
 * File: CountLetters.cpp
 * -------------------------
 *  This program takes a filename and prints the number of times
 *  each letter of the alphabet appears in the file.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "simpio.h"
#include "vector.h"
using namespace std;

/* Function prototypes */

void CountLetters(string filename);


/* Main program */

int main() {
	string filename = getLine("Input file: ");
	CountLetters(filename);
	return 0;
}

/*
 * Function: CountLetters
 * Usage: void CountLetters(filename);
 * ------------------------------------
 *  This function takes a filename and prints the number of
 *  times each letter appear in that file
 */

void CountLetters(string filename) {
	ifstream infile;
	infile.open(filename.c_str());
	if(infile.fail()) {
		cout << "Unable to open that file." << endl;
		return;
	}
	Vector<int> letterCounts(26);
	char ch;
	while((infile.get(ch))) {
		if (isalpha(ch)) {
			letterCounts[tolower(ch) - 'a']++;
		}
	}
	infile.close();
	for (char c = 'a'; c <= 'z'; c++) {
		cout << c << ": " << letterCounts[c -'a'] << endl;
	}
	return;
}
