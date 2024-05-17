/*
 * File: ex03.cpp
 * -------------------
 *  This program implement mySubstr(str, pos, n) function that
 *  returns the substring of str beginning at position pos and
 *  containing at most n characters.
 *  Rules that mySubstr follows:
 *  	1. if n is missing or greater thant the length of the 
 *  	string, the substring should extend to the end of the 
 *  	original string.
 *  	2. if pos is greater than the length of the string, 
 *  	substr should call error with an appropriate message.
 */

#include <string>
#include <cctype>
#include <iostream>
#include "simpio.h"
#include "error.h"
using namespace std;

string mySubstr(string str, int pos, int n = 0);

int main() {
	string str = getLine("Enter str: ");
	int pos = getInteger("Enter pos: ");
	int n = getInteger("Enter n: ");
	cout << mySubstr(str, pos, n) << endl;
	cout << mySubstr(str, pos) << endl;
	return 0;
}

string mySubstr(string str, int pos, int n) {
	if (pos > str.length()) error("Out of index");
	string result = "";
	if (n == 0) n = str.length();
	int end = pos + n;
	for (int i = pos; i < end; i++) {
		if (i < str.length()) {
			result += str[i];
		} else {
			return result;
		}
	}
	return result;
}
	



