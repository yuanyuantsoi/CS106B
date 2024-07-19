/*
 * File: ex06.cpp
 * ----------------------
 *  This program counts the number of function calls  made
 *  during the evaluation of the correponding Fibonacci calculation.
 */

#include <iostream>
#include <string>
#include <iomanip>
using  namespace std;

/* Constant */
const int TABULAR_WIDTH = 10;


/* Function prototypes*/

int countFib1(int i);
int countFib2(int i);
int fib1(int n, int & nCall);
int fib2(int n, int & nCall);
int additiveSequence(int n, int t0, int t1, int & nCall);


/* Main program */

int main() {
	cout << " This program counts the number of calls mady by the " 
		<< "two algorithms used to compute the Fibonacci sequence." << endl;
	cout << right << setw(TABULAR_WIDTH)  << "n" 
		<< right << setw(TABULAR_WIDTH) << "fib1" 
		<< right << setw(TABULAR_WIDTH) << "fib2" << endl;

	cout << right << setw(TABULAR_WIDTH) << "--"
	     << right << setw(TABULAR_WIDTH) << "----"
	     << right << setw(TABULAR_WIDTH) << "----" << endl;
	
	for (int i = 0; i <= 12; i++) {
		cout << right << setw(TABULAR_WIDTH) << i
                     << right << setw(TABULAR_WIDTH) << countFib1(i)
                     << right << setw(TABULAR_WIDTH) << countFib2(i) << endl;
	}
	return 0;
}



int countFib1(int i) {
	int nCall = 0;
	fib1(i, nCall);
	return nCall;
}

int countFib2(int i) {
	int nCall = 0;
	fib2(i, nCall);
	return nCall + 1;
}

/*
 * Function: fib1
 * Usage: int f = fib1(n, nCall);
 * ---------------------------------
 *  Returns the nth term in the Fibonacci sequence using the following 
 *  recursive formulation:
 *  	
 *  	fib(0) = 0;
 *  	fib(1) = 1;
 *  	fib(n) = fib(n-1) + fib(n-2);
 */
int fib1(int n, int & nCall) {
	nCall++;
	if (n < 2) {
		return n;
	} else {
		return fib1(n - 1, nCall) + fib1(n - 2, nCall);
	}
}
/*
 * Function: fib2
 * Usage: int n = fib2(n, nCall);
 * -------------------------
 *  Return the nth term in the Fibonacci sequence using a different 
 *  recursive method - fib2() as a warpper.
 */
int fib2(int n,int & nCall) {
	return additiveSequence(n, 0, 1, nCall);
}

int additiveSequence(int n, int t0, int t1, int & nCall) {
	nCall++;
	if (n == 0) return 0;
	if (n == 1) return t1;
	return additiveSequence(n - 1, t1, t0 + t1, nCall);
}

