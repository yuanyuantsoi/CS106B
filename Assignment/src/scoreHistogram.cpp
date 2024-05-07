/*
 * File: scoreHistogram.cpp
 * --------------------------
 *  CS106B - Handout#9 (Jan 14, 2008)
 *  5.File processing and vectors
 *  Read scores from a file, and print  the score histogram.
 */

#include <iostream>
#include <fstream>
#include "vector.h"
#include "strlib.h"
#include "simpio.h"
using namespace std;

/* Function prototypes */

string promptUserForFile(ifstream & infile, string prompt = "");


/* Main function */

int main() {
	ifstream infile;
	promptUserForFile(infile, "Enter file name: ");
	string line;
	Vector<int> scoreGram;
	for (int i = 0; i < 10; i++) scoreGram.add(0);
	while (getline(infile, line)) {
		int score = stringToInteger(line);
		scoreGram[score/10]++;
	}
	infile.close();
	for (int i = 0; i < 10; i++) {
		int h = i * 10;
		int t = i * 10 + 9;
		string gram = "";
		for (int j = 0; j < scoreGram[i]; j++) {
		       gram += "X";
		}	       
		cout << h  << "-" << t << ": "<< gram << endl;
	}

	return 0;
}



string promptUserForFile(ifstream & infile, string prompt) {
	while (true) {
		string filename = getLine(prompt);
		infile.open(filename.c_str());
		if (!infile.fail()) return filename;
		infile.clear();
		cout << "Can't open file, please try again." << endl;
		if (prompt == "") prompt = "Input file: ";
	}
}
