/*
 * File: ReverseString.cpp
 * ---------------------------
 *  H17.Handout#3 - Problem 5: ReverseString
 *
 *  The program returns the string in reverse order.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Function prototypes */

string reverseString(string str);

/* Main program */
int main() {
	string str = getLine("Enter string: ");
	
	// Reverse string in iterative method
	string revStr = "";
	for (int i = 0; i < str.length(); i++) {
		revStr = str[i] + revStr;
	}
	cout << "revStr(iterative) = " << revStr << endl;
	cout << "revStr(recursive) = " << reverseString(str) << endl;
	return 0;
}

/*
 * Function: reverseString
 * Usage: string revStr = reverseString(str);
 * --------------------------------------------
 *  Reverse the string using the recursive techniques.
 */

string reverseString(string str) {
	//Simple case
	if (str == "") return "";
	
	// Recursive case
	return reverseString(str.substr(1)) + str[0];
}
	
