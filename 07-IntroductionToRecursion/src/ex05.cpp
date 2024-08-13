/*
 * File: ex05.cpp
 * --------------------------
 *  The progream implements an  iterative method of the 
 *  function fib(n).
 */

#include <iostream>
#include <string>
#include "simpio.h"
using namespace std;

int fib(int n);

int main() {
	for (int n = 0; n <= 10; n++) {
		cout << "fib(" << n<< ") = " << fib(n) << endl;
	}
	return 0;
}

/*
 * Function: fib
 * Usage: int n = fib(n);
 * --------------------------------
 *  Implements the function fib(n) in iterative method.
 */

int fib(int n) {
	int result = 0;
	int last = 1;
	for (int i = 1; i < n; i++) {
		result += last;
		last = result;
	}
	return result;
}
