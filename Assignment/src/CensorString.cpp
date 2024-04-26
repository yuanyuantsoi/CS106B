/*
 * File: CensorString.cpp
 * ----------------------
 *  This program removes all occurrences of characters.(case sensitive)
 *  The function is written in two ways.
 *
 *  1. Return a completely new string. ---> CensorString1
 *
 *  2. Modify the original string. ---> CensorString2
 *
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
using namespace std;

/* Function prototypes */

string CensorString1(string text, string remove);

void CensorString2(string & text, string remove);

/* Main Functions */

int main() {
	while (true) {
		cout << "Press Q to quit: " << endl;

		string str = getLine("Input string: ");
		
		if ((str == "Q") || (str == "")) break;
	
		string rmStr = getLine("Remove Characters: ");
		string result = CensorString1(str, rmStr);
		cout << "The first way: result = " << result << endl;
		cout << endl;

		CensorString2(str, rmStr);
		cout << "The sencond way: result = " << str << endl;
		cout << endl;
	}
		return 0;
}

/*
 * Functon: CensorString1
 * Usage: string result = CnesorString1(text, remove);
 * ---------------------------------------------------
 * Removes all occurrences of characters and return a new string.
 */
string CensorString1(string text, string remove) {
	string result;
	for (int i = 0; i < text.length(); i++) {
		char ch = text[i];
		if (remove.find(ch) == string::npos) {
			result += ch;
		}
	}
	return result;
}



/*
 * Function: CensorString2
 * Usage: void CensorString2(text, remove);
 * -----------------------------------------
 *  Removes all occurrences on the original string.
 */
void CensorString2(string & text, string remove) {
	for (int i = 0; i < remove.length(); i++) {
		int found = 0;
		char rm = remove[i];
		while ((found = text.find(rm, found)) != string::npos) {
			text.erase(found,1);
		}
	}
	return;
}










