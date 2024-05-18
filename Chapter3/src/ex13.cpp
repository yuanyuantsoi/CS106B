/*
 * File: ex13.cpp
 * -----------------------------
 *  This program implments the function createOrdinalForm(n) that 
 *  returns the ordinal form of the number n as a string.
 */

#include <string>
#include <cctype>
#include "simpio.h"
#include "strlib.h"
using namespace std;

string createOrdinalForm(int n); 

int main() {
	while (true) {
		int n = getInteger("Enter a num: ");
		if (n == 0) break;
		cout << "The ordinal form is " << createOrdinalForm(n) << endl;
	}
	return 0;
}


string createOrdinalForm(int n) {
	int dig_1 = n % 10;
	string str = integerToString(n);
	if (dig_1 == 1 && n != 11) return str + "st";
	if (dig_1 == 2 && n != 12) return str + "nd";
	if (dig_1 == 3 && n != 13) return str + "rd";
	return str + "th";
}
