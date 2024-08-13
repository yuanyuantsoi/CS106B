/*
 * File: ex08.cpp
 * ----------------
 *  The program implements the digitalRoot(n)  function.
 */

#include <iostream>
#include "simpio.h"
#include "error.h"
using namespace std;

/* Function prototypes */
int digitalRoot(int n);
int digitSum(int n);

/* Main program */
int main() {
	int n = getInteger("Enter n = ");
	cout << "The digit root of " << n << " is " << digitalRoot(n) << endl;
	return 0;
}

/*
 * Function: digitalRoot
 * Usage: int n = digitRoot(n);
 * ---------------------------------
 *  Returns the digital root of its argument.
 */

int digitalRoot(int n) {
	int result = digitSum(n);
	if (result >= 10) result = digitalRoot(result);
	return result;
}

/*
 * Function: digitSum
 * Usage: int n = digitSum(n);
 * -------------------------------
 *  Returns the sum of its digits.
 */

int digitSum(int n) {
	if (n == 0) return 0;
	return (n % 10) + digitSum(n / 10);
}
