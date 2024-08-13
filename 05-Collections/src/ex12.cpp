/*
 * File: ex12.cpp
 * -----------------------------------------------
 *  This program uses a stack to reverse a sequence of
 *  integers from the console one numer per line.
 */

#include <iostream>
#include <iomanip>
#include "stack.h"
#include "simpio.h"
using namespace std;

/* Constants */
const int SENTINEL = 0;

/* Main program */
int main() {
	Stack<int> rvsList;
	
	cout << "Enter a list of integers, ending with " << SENTINEL << ": " << endl;
	while (true) {
		int value = getInteger("? ");
	      	if (value == SENTINEL) break;
		rvsList.push(value);
	}
	
	cout << "Those integers in reverse order are: " << endl;
	while (!rvsList.isEmpty()) {
		int n = rvsList.pop();
		cout << setw(4) << n << endl;
	}
	return 0;
}

