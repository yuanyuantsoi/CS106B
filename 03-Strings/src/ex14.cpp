/*
 * File: ex14.cpp
 * ----------------------------------------
 *  This progarm implements a function addCommas(digits) that
 *  takes a string of decimal digits representing a number and returns the
 *  string formed by inserting commas at every third position.
 */

#include <string>
#include <cctype>
#include "simpio.h"
#include "strlib.h"
using namespace std;

string addCommas(string digits);

int main() {
	while (true) {
		string digits;
		cout << "Enter a number: ";
		getline(cin, digits);
		if (digits == "") break;
		cout << addCommas(digits) << endl;
	}
	return 0;
}

string addCommas(string digits) {
	int num = 0;
	string result = "";
	for (int i = digits.length() - 1; i >= 0; i--) {
		result = digits[i] + result;
		if (num < 2) {
			num++;
		} else if (num == 2 && i != 0) {
			num = 0;
			result = "," + result;
		}
	}
	return result;
}

