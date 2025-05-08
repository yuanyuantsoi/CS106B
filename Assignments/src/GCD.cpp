/*
 * File: GCD.cpp
 * --------------------------------
 *  H17.SectionHandout#3 - Problem6:GCD
 *  
 *  This program used Euclid's insight to compute
 *  the greatest common divisor of x and y.
 */

#include <iostream>
#include "simpio.h"
using namespace std;


/* Function prototypes */

int GCD(int x, int y);

/* Main program */

int main() {
	int x = getInteger("Enter x = ");
	int y = getInteger("Enter y = ");
	cout << "GCD(x, y) = " << GCD(x, y) << endl;
	return 0;
}

int GCD(int x, int y) {
	int remainder = x % y;
	if (remainder == 0) return y;
	return GCD(y, remainder);
}
