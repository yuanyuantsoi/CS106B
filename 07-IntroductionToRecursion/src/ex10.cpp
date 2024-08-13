/*
 * File: ex10.cpp
 * -------------------------
 *  The function implements the function reverse(str).
 */

#include <iostream>
#include <string>
#include "simpio.h"
using namespace std;

/* Function prototypes */
string reverse(string str);

/* Main program */
int main() {
	string str = getLine("Enter string: ");
	cout << "The reverse of that string is: " << reverse(str) << endl;
	return 0;
}

/*
 * Function: reverse
 * Usage: string rvsStr = reverse(str);
 * ----------------------------------------------
 *  The function takes a string as argument and returns the reverse of 
 *  that string.
 */
string reverse(string str) {
	int len = str.length();
	if (len == 1) return str;
	return reverse(str.substr(1)) + str[0];
}

