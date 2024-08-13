/*
 * File: ex04.cpp
 * ---------------------
 *  The program implements the gcd function.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "simpio.h"
using namespace std;

int gcd(int x, int y);

int main() {
	while (true) {
		int x = getInteger("Enter x = ");
		int y = getInteger("Enter y = ");
		cout << "The greatest common divisor of " << x << " and " << y << " is "
			<< gcd(x, y) << endl;
		cout << endl;
		string str = getLine("Enter 'Q' to quit: ");
		if (str == "Q") break;
		cout << endl;
	}
	return 0;
}

/*
 * Function: gcd
 * Usage: int n = gcd(x, y);
 * ---------------------------
 *  Use Euclid's insight to implment the gcd in recursive way to 
 *  computes the greates common divisor of x and y.
 */
int gcd(int x, int y) {
	if (y > x) return gcd(y, x);
	if ((x % y) == 0)  return y;
	return gcd(x % y, y);
}
