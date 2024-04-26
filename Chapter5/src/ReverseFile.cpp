/*
 * File: ReverseFile.cpp
 * ----------------------
 *  This program displays the lines of an input file in reverse order.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "vector.h"
using namespace std;

/* Function prototypes */

string promptUserForFile(ifstream & infile, string prompt = " ");
void readEntireFile(istream & is, Vector<string> & lines);



/* Main program */

int main() {
	ifstream infile;
	Vector<string> lines;
	promptUserForFile(infile, "Input file: ");
	readEntireFile(infile, lines);
	infile.close();
	for (int i = lines.size() - 1; i >= 0; i--) {
	       cout << lines[i] << endl;
	}
	return 0;
}

/*
 * Function: readEntireFile
 * Usage: readEntireFile(is, lines);
 * -------------------------------------
 *  Reads the entire contents of the specified input stream into the
 *  string vector lines. The client is responsible for opening and closing the stream.
 */
void readEntireFile(istream & is, Vector<string> & lines) {
	string line;
	while (getline(is, line)) {
		lines.add(line);
	}
}

/*
 * Function: promptUserForFile
 * Usage: promptUserForFile(infile, prompt);
 * ------------------------------------------
 *  Asks the user for the name of an input file and opens the reference parameter infile
 *  using that name, which is returned as the result of the function. If the requested file 
 *  does not exist, the user is given additional chances to enter a valid file name. The
 *  optional prompt argument is used to give the user more information about the desired
 *  input file.
 */
string promptUserForFile(ifstream & infile, string prompt) {
	while (true) {
		cout << prompt;
		string filename;
		getline(cin, filename);
		infile.open(filename.c_str());
		if (!infile.fail()) return filename;
		infile.clear();
		cout << "Unable to open that file. Try again." << endl;
		if (prompt == " ") prompt = "Input file: ";
	}
}
			
