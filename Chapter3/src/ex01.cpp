/*
 * File: ex01.cpp
 * ------------------------
 *  This program implements the function endsWith(str, suffix)
 *  which returns true if str ends with suffix. (str could be 
 *  either a string or a character).
 */

#include "simpio.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool endsWith(string str, string suffix);

int main() {
	string str = getLine("Enter str: ");
	string suffix = getLine("Enter suffix: ");
	if (endsWith(str, suffix)) {
		cout << str << " ends with " << suffix << endl;
	} else {
		cout << str << " does not end with " << suffix << endl;
	}
	return 0;
}

bool endsWith(string str, string suffix) {
	if (str.length() < suffix.length()) return false;
	for (int i = 0; i < suffix.length(); i--) {
		if (str[str.length() - 1 - i] != suffix[suffix.length() - 1 - i]) return false;
	}
	return true;
}

