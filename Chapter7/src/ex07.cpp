/*
 * File: ex07.cpp
 * ----------------
 *  THe program implementats the recursive digitSum.
 */

#include <iostream>
#include "simpio.h"
#include "error.h"
using namespace std;

/* Function prototypes */
int digitSum(int n);

/* Main program */
int main() {
	int n = getInteger("Enter n = ");
	cout << "The digit sum of " << n << " is " << digitSum(n) << endl;
	return 0;
}

/*
 * Function: digitSum
 * Usage: int n = digitSum(n);
 * -----------------------------------
 *  The function takes a non negative integer and return the sum of its digits.
 */
int digitSum(int n) {
	if (n < 0) error("Please enter nonnegative integer.");
	if (n == 0) return 0;
	return (n % 10) + digitSum(n / 10);
}

