/*
 * File: ex11.cpp
 * ----------------------------
 *  The program implements the function integerToString without using 
 *  the streams rather than by exploiting the recursive decomposition.
 */

#include <iostream>
#include "simpio.h"
#include <string>
using namespace std;

/* Function prototypes */
string integerToString(int n);
string numToString(int n);

/* Main program */
int main() {
	int n = getInteger("Enter num = ");
	cout << "The string version of " << n << " is: " << integerToString(n) << endl;
	return 0;
}

/*
 * Function: integerToString
 * Usage: string str = integerToString(n);
 * -----------------------------------------------
 *  Return the string version of the num n, using the recursive decomposition rather than 
 *  the streams function.
 */

string integerToString(int n) {
	if (n == 0) return "";
	return integerToString(n / 10) + numToString(n % 10);
}

/*
 * Function: numToString
 * Usage: string n = numToString(n);
 * ------------------------------------------------
 *  Return the string version of one-digit number.
 */
string numToString(int n) {
	switch (n) {
		case 1: return "1";
		case 2: return "2";
		case 3: return "3";
		case 4: return "4";
		case 5: return "5";
		case 6: return "6";
		case 7: return "7";
		case 8: return "8";
		case 9: return "9";
		case 0: return "0";
		default: return "error";
	}
}
