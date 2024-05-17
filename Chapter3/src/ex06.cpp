/*
 * File: ex06.cpp
 * ----------------------
 * This program implements the function acronym
 * that takes a string and return the acronym formed
 * from that string.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
using namespace std;

string acronym(string str);

int main() {
	string str = getLine("Enter str: ");
	cout << "The acronym of the " << str << " is " << acronym(str) << endl;
	return 0;
}

string acronym(string str) {
	string acr = ""; 
	bool headLetter = true;
	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];
		if (isalpha(ch)) {
			if (headLetter)  {
				acr += ch;
				headLetter = false;
			}
		} else {
			headLetter = true;
		}			
	}

	return acr;
}
