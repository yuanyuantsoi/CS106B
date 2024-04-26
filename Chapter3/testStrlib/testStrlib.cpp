/*
 * File: testStrlib.cpp
 * ----------------------
 *  This program is used to test the strlib.h library provided by 
 *  the stanford library.
 */

#include <iostream>
#include "strlib.h"
#include "simpio.h"
using namespace std;

int main() {
	cout << "Function 1: integerToString(n) " << endl;
	int n = getInteger("Enter an integer n = ");
	string test = "test string";
//	cout << "Output: n + test string " << n << test << endl;
//	string noConvert = n + test;
	string withConvert = integerToString(n) + " " + test;
	cout << "Output: integerToString(n) + test string: " << withConvert << endl;
	return 0;
}

