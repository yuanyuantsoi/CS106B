/*
 * File: ex02.cpp
 * ----------------------
 *  This program implements the raiseToPower function.
 */

#include <iostream>
#include <string>
#include "simpio.h"
using namespace std;

int raiseToPower(int n, int k);

int main() {
	while (true) {
		int n = getInteger("Enter n = ");
		int k = getInteger("Enter k = ");
		cout << "n^k = " << raiseToPower(n, k) << endl;
		string str = getLine("Enter 'Q' to quit: ");
		if (str == "Q") break;
		cout << endl;
	}
}

/*
 * Function: raiseToPower
 * Usage: int n = raiseToPower(n, k);
 * -------------------------------------
 *  The function raiseToPower calculates n^k using recursive implementation.
 */
int raiseToPower(int n, int k) {
	if (k == 0) return 1;
	return n * raiseToPower(n, k - 1);
}

