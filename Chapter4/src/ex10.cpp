/*
 * File: ex10.cpp
 * ---------------------------------
 *  This program copies an input file to an output file,
 *  replacing all tab characters by the appropriate number
 *  of spaces.
 */

#include <fstream>
#include <iostream>
#include "simpio.h"
#include "filelib.h"
#include <string>
#include <cctype>
using namespace std;

string replaceTabWithBlank(string str);

int main() {
	ifstream infile;
	promptUserForFile(infile, "Input file: ");

	string outfileName = getLine("Output file: ");
	ofstream outfile;
	outfile.open(outfileName.c_str());

	string line;
	while (getline(infile, line)) {
		line = replaceTabWithBlank(line);
		outfile << line << endl;
	}
	
	infile.close();
	outfile.close();

	return 0;
}

string replaceTabWithBlank(string str) {
	string result = "";
	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];
		if (ch == '\t')  {
			int nBlank = 8 - (result.length() % 8);
			cout << i << endl;
			result  += string(nBlank, ' ');
		}else {
			result += ch;
		}
	}
	return result;
}


