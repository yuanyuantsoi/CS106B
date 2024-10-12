/*
 * File: PrintInBinary.cpp
 * -----------------------------
 *  The program takes a decimal number and print it in binary form.
 */

#include <iostream>
#include "simpio.h"
using namespace std;

/* Function prototypes */

void printInBinary(int num);

/* Main program */

int main() {
	int n = getInteger("Enter num = ");
	printInBinary(n);
	return 0;
}


/* 
 * Function: printInBinary
 * Usage: void printInBinary(n);
 * ------------------------------------
 *  The function takes a decimal number and print it
 *  in binary form.
 */
void printInBinary(int num) {
	// Simple case
	if (num < 2) {
		cout << num;
		return;
	}

	// Recursive case
	int m = num % 2;
	printInBinary(num / 2);
	cout << m;
}
