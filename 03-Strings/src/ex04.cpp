/*
 * File: ex04.cpp
 * ------------------------------
 * This program implements a function capitalize(str)
 * that returns a string in which initial character is 
 * capitalized (if it is a letter) and all other letters
 * are converted to lower case.
 */

#include <string>
#include <cctype>
#include "simpio.h"
#include <iostream>
using namespace std;

string capitalize(string str);

int main() {
	string str = getLine("Enter the str: ");
	cout << capitalize(str) << endl;
	return 0;
}


string capitalize(string str) {
	string result = "";
	bool init = false;
	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];
		if (isalpha(ch)) {
			if (!init) {
				init = true;
				result += toupper(ch);
			} else {
				result += tolower(ch);
			}
		} else {
			result += ch;
		}
	}
	return result;
}
	
