/*
 * File: ex01.cpp
 * ----------------
 *  The program implements the function cannonball.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "simpio.h"
using namespace std;

int cannonball(int nHeight);

int main() {
	while (true) {
		int n = getInteger("Enter the height of the pyramid: ");
		cout << "The number of cannonballs it contains: " << cannonball(n) << endl;
		string str = getLine("Press 'Q' to quit");
		if (str == "Q") break;
	}	
	return 0;
}


/*
 * Function: cannonball
 * Usage: int n = cannonball(int nHeight);
 * ------------------------------------------
 *  This program takes as its argument the height of the pyramid and 
 *  returns the number of cannonballs it contains.
 */

int cannonball(int nHeight) {
	if (nHeight == 0) return 0;
	return nHeight * nHeight + cannonball(nHeight - 1);
}

