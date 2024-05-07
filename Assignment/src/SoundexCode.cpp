/*
 * File: SundexCode.cpp
 * ---------------------
 *  CS106B - Handout#9 (Jan 14, 2008)
 *  4.strings
 *  by yuan @2024/05/06 17:01
 *
 *  This program translate sumname to Soundex code accroading to the following steps:
 *  
 *  	1. keep the first leeter of the surname
 *  	2.convert all other letters in the surname
 *  	3. remove any consecutive duplicate digits
 *  	4. remove any zeros
 *  	5. make resulting code exactly length 4
 */

#include <iostream>
#include <string>
#include <cctype>
#include "strlib.h"
#include "simpio.h"

using namespace std;

string letterToDigit(char ch);


int main() {
	string surname = getLine("Enter surname (RETURN to quit): ");
	surname = trim(surname);
	string suCode = "";
       suCode += toupper(surname[0]);
	for (int i = 1; i < surname.length(); i++) {
	 	suCode += letterToDigit(surname[i]);
	}

	for (int i = 2; i < suCode.length(); i++) {
		char last = suCode[i - 1];
		if (suCode[i] == last) {
		       	suCode.erase(i, 1);
			i--;
		}
	}
	int found = 0;
	while ((found = suCode.find('0', found)) != string::npos) {
		suCode.erase(found, 1);
	}

	suCode += "000";
	suCode = suCode.substr(0, 4);
	cout << "Soundex code for " << surname << " is " << suCode << endl;
	return 0;
}




string letterToDigit(char ch) {
	ch = toupper(ch);
	string letter0 = "AEIOUHWY";
	string letter1 = "BFPV";
	string letter2 = "CGJKQSXZ";
	string letter3 = "DT";
	string letter4 = "MN";
	string letter5 = "L";
	string letter6 = "R";
	if (letter0.find(ch) != string::npos) return "0";
	if (letter1.find(ch) != string::npos) return "1";
	if (letter2.find(ch) != string::npos) return "2";
	if (letter3.find(ch) != string::npos) return "3";
	if (letter4.find(ch) != string::npos) return "4";
	if (letter5.find(ch) != string::npos) return "5";
	if (letter6.find(ch) != string::npos) return "6";
	string str = "";
	return str + ch;

}
