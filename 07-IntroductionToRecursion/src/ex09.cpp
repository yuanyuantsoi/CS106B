/*
 * File: ex08.cpp
 * -------------------------
 *  The program implements the c(n, k) using the Pascal's Triangle.
 */

#include <iostream>
#include "simpio.h"
using namespace std;

/* Function prototypes */
int combinations(int n, int k);

/* Main program */
int main() {
	int n = getInteger("Enter n = ");
	int k = getInteger("Enter k = ");
	cout << "c(n, k) = " << combinations(n, k) << endl;
	return 0;
}

/*
 * Function: combinations
 * Usage: int n = combinations(n, k);
 * -------------------------------------------------------
 *  Return  c(n, k) defined by the mathematical combinations.
 */
int combinations(int n, int k) {
	if(k == 0) return 1;
	if(n == k) return 1;
	return combinations(n - 1, k - 1) + combinations(n - 1, k);
}
