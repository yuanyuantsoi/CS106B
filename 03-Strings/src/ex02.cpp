/*
 * File: ex03.cpp
 * -----------------------
 *  This program implements a function trim(str) that 
 *  returns a new string formed by removing all whitespace
 *  characters.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
using namespace std;

string myTrim(string str);

int main() {
	string str = getLine("Enter str: ");
	cout << "After trim: <" << myTrim(str) << ">" << endl;
	return 0;
}

string myTrim(string str) {
	string result = "";
	for (int i = 0; i < str.length(); i++) {
		if (!isspace(str[i])) {
			result += str[i];
		}
	}
	return result;
}
