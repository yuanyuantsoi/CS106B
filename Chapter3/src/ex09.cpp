/*
 * File: ex09.cpp
 * -------------------------------------------------
 * This program implements the function removeDoubledLetters(str)
 * that returns a new string in which an duplicated characters in
 * str have been replaced by a single copy.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
using namespace std;

string removeDoubledLetters(string str);

int main() {
	string str = getLine("Enter the letter: ");
	cout << str << " -> " << removeDoubledLetters(str) << endl;
	return 0;
}

string removeDoubledLetters(string str) {
	string result = "";
	for (int i = 0; i < str.length(); i++) {
		if ((i == 0) || (str[i] != str[i-1])) result += str[i];
	}
	return result;
}
