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
#include "map.h"
#include <cctype>
#include <sstream>
#include "error.h"
using namespace std;

/* Function prototypes */


void initializeMorseCode(Map<char, string> & morsecode);
string translateString(string str);
char findMatchedLetter(Map<char, string> morsecode, string code);


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

char findMatchedLetter(Map<char, string> morsecode, string code) {
	for (char ch : morsecode) {
		if (morsecode[ch] == code) return ch;
	}
	error("Can't find code: " + code);
	return 0;
}


/*
 * Function: translateString
 * Usage: newStr = translateString(str);
 * ---------------------------------------------
 *  The function takes a string and translate it to morse code or letter.
 */
string translateString(string str) {
	Map<char, string> morsecode; //store the morse code for encoding and decoding
	initializeMorseCode(morsecode);
	
	string result = "";

	if (isalpha(str[0])) {
		for (int i = 0; i < str.length(); i++) {
			char ch = str[i];
			if (isalpha(ch)) {
				result += morsecode[toupper(ch)];
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
				result += findMatchedLetter(morsecode, code);
			}
		}
		if (start >= 0) result += findMatchedLetter(morsecode, str.substr(start));
	}

	return result;
}


void initializeMorseCode(Map<char, string> & morsecode) {
	morsecode.clear();

	morsecode.put('A', ".-"); // A .-
	morsecode.put('B', "-..."); // B -...
	morsecode.put('C', "-.-."); //C -.-.
	morsecode.put('D', "-.."); //D
	morsecode.put('E', "."); //E
	morsecode.put('F', "..-."); //F
	morsecode.put('G', "--."); //G
	morsecode.put('H',"...."); //H
	morsecode.put('I', ".."); //I
	morsecode.put('J', ".---"); //J
	morsecode.put('K', "-.-"); //K
	morsecode.put('L', ".-.."); // L
	morsecode.put('M', "--"); // M
	morsecode.put('N', "-."); // N
	morsecode.put('O', "---"); // O
	morsecode.put('P', ".--."); // P
	morsecode.put('Q', "--.-"); //Q
	morsecode.put('R', ".-."); //R
	morsecode.put('S', "..."); // S
	morsecode.put('T', "-"); //T
	morsecode.put('U', "..-"); //U
	morsecode.put('V', "...-"); //V
	morsecode.put('W', ".--"); //W
	morsecode.put('X', "-..-"); // X
	morsecode.put('Y', "-.--"); //Y
	morsecode.put('Z', "--.."); // Z
}








