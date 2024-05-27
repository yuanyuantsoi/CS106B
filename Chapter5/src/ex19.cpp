/*
 * File: ex19.cpp
 * ---------------
 *  This program reads in lines from the user and traslates each line
 *  either to or from Mosrse code, depending on the first character of the line;
 *  	1. if the line starts with a letter, translate it to Morse code. Any
 *  	characters other than 26 letters should simply be ignored.
 *  	2.  line start with period(dot) or hyphen(dash-),translate it to leters.
 *  	each sequence of leters will be separated by spaced, and other characters
 *  	should be ignored.
 *  	3. the program stops when reads in a blank line.
 */ 

#include <iostream>
#include <iomanip>
#include "strlib.h"
#include "simpio.h"
#include "vector.h"
#include <string>
#include <cctype>
#include <sstream>
#include "error.h"
using namespace std;

/* Function prototypes */


void initializeMorseCode(Vector<string> & morsecode);
string translateString(string str);
int findMatchedIndex(Vector<string> morsecode, string code);


/* Main program*/

int main() {
	cout << "Morse Code translator" << endl;
	while (true) {
		string str = getLine("> ");
		if (str.empty()) break;
		string translation = translateString(str);
		cout << translation << endl;
	}
	return 0;
}

int findMatchedIndex(Vector<string> morsecode, string code) {
	for (int i = 0; i < morsecode.size(); i++) {
		if (code == morsecode[i])
			return i;
	}
	error("No Matched code: " + code);
	return 0;
}


/*
 * Function: translateString
 * Usage: newStr = translateString(str);
 * ---------------------------------------------
 *  The function takes a string and translate it to morse code or letter.
 */
string translateString(string str) {
	Vector<string> morsecode; //store the morse code for encoding and decoding
	initializeMorseCode(morsecode);
	
	string result = "";

	if (isalpha(str[0])) {
		for (int i = 0; i < str.length(); i++) {
			char ch = str[i];
			if (isalpha(ch)) {
				result += morsecode[toupper(ch) - 'A'];
				result += " ";
			}
		}
	} else {
		int start = -1;
		for (int i = 0; i < str.length(); i++) {
			char ch = str[i];
			if ((ch == '.') || (ch == '-')) {
				if (start < 0) start = i;
			} else if (start >= 0) {
				string code = str.substr(start, i - start);
				start = -1;
				result += char (findMatchedIndex(morsecode, code) + 'A');
			}
		}
		if (start >= 0) result += char (findMatchedIndex(morsecode, str.substr(start)) + 'A');
	}

	return result;
}


void initializeMorseCode(Vector<string> & morsecode) {
	morsecode.clear();

	morsecode.add(".-"); // A .-
	morsecode.add("-..."); // B -...
	morsecode.add("-.-."); //C -.-.
	morsecode.add("-.."); //D
	morsecode.add("."); //E
	morsecode.add("..-."); //F
	morsecode.add("--."); //G
	morsecode.add("...."); //H
	morsecode.add(".."); //I
	morsecode.add(".---"); //J
	morsecode.add("-.-"); //K
	morsecode.add(".-.."); // L
	morsecode.add("--"); // M
	morsecode.add("-."); // N
	morsecode.add("---"); // O
	morsecode.add(".--."); // P
	morsecode.add("--.-"); //Q
	morsecode.add(".-."); //R
	morsecode.add("..."); // S
	morsecode.add("-"); //T
	morsecode.add("..-"); //U
	morsecode.add("...-"); //V
	morsecode.add(".--"); //W
	morsecode.add("-..-"); // X
	morsecode.add("-.--"); //Y
	morsecode.add("--.."); // Z
}








