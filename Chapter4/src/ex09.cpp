/*
 * File: ex09.cpp
 * -----------------------------------------------------------
 *  This program asks the user for an input file, an output file,
 *  and a string of letters to be eliminated.
 */

#include <fstream>
#include <iostream>
#include "simpio.h"
#include "filelib.h"
using namespace std;

string removeBanishLetters(string str, string remove);

int main() {
	ifstream infile;
	promptUserForFile(infile, "Input file: ");
	
	string outfileName = getLine("Output file: ");
	ofstream outfile;
	outfile.open(outfileName.c_str());

	string remove = getLine("Letters to banish: ");

	string line;
	while (getline(infile, line)) {
		line = removeBanishLetters(line, remove);
		outfile << line << endl;
	}
	infile.close();
	outfile.close();
	return 0;
}

string removeBanishLetters(string str, string remove) {
	string result = "";
	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];
		if (remove.find(toupper(ch)) == string::npos && remove.find(tolower(ch)) == string::npos) result += ch;
	}
	return result;
}
