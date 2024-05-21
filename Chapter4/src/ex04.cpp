/*
 * File: ex04.cpp
 * ------------------------------------
 *  This program reads a file, and reports
 *  how many lines, words, and characters
 *  appear in it. A word consists of consecutive
 *  sequency of any characters except whitespace
 *  characters.
 *  The output should be displayed in a coloumn that is
 *  aligned on the right but which expands to fit the data.
 */

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include "simpio.h"
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

string promptUserForFile(ifstream & infile, string prompt = "");
int countWordsInLine(string line);
int countCharsInLine(string line);

int main() {
	ifstream infile;
	
	// reads in a file
	promptUserForFile(infile, "Input file: ");
	
	// count chars, words and lines in file
	int nChars, nWords, nLines;
	nChars = nWords = nLines = 0;
	string line;
	while (getline(infile, line)) {
		nLines++;
		nWords += countWordsInLine(line);
		nChars += countCharsInLine(line);
	}
	infile.close();

	//reports the num of chars, words and lines
	int width = log10(nChars) + 1;
	cout << "Chars: " << setw(width) << nChars << endl;
	cout << "Words: " << setw(width) << nWords << endl;
	cout << "Lines: " << setw(width) << nLines << endl;
	return 0;
}

string promptUserForFile(ifstream & infile, string prompt) {
	while (true) {
		string filename;
		cout << prompt;
		getline(cin, filename);
		infile.open(filename.c_str());
		if (!infile.fail()) return filename;
		cout << "Unable to open file, please try again." << endl;
		infile.clear();
		if (prompt == "") prompt = "Input file: ";
	}
}

int countWordsInLine(string line) {
	int nWords = 0;
	string word;
	istringstream stream(line);
	while (!stream.eof()) {
		stream >> word;
	        nWords++;
	}	
	return nWords;
}

int countCharsInLine(string line) {
	return line.length();
	int nChar = 0;
	for (int i = 0; i < line.length(); i++) {
		if (!isspace(line[i])) nChar++;
	}
	return nChar;
}


