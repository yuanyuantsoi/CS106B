/*
 * File: Cannonball.cpp
 * -----------------------------------
 *  The program writes the recursive function Cannonball.
 */

#include <iostream>
#include <iomanip>
#include "simpio.h"
using namespace std;

/* Function prototypes */

int Cannonball(int height);
int getNumOfBallsInOneLine(int height);

/* Main program */

int main() {
	for (int h = 0; h < 10; h++) {
		cout << "height = " << h
			<< setw(20) 
			<< "Cannonballs = " << Cannonball(h) << endl;
	}
	return 0;
}

/*
 * Function: Cannonball
 * Usage: int n = Cannonball(h);
 * ---------------------------------
 *  The recursive function Cannonball that takes as its argument the 
 *  height of the pyramid and returns the number of cannonballs therein.
 *  Insight: 行号和每行中cannonball的个数关系： 行号金字塔
 *  						------------------------------------------
 *  								1
 *  							2		3
 *  							4	5	6
 *  						 7	8	9	10
 *  						11	12	13	14	15
 *						------------------------------------------
 * 问题转变成如果一个行号金字塔，如何快速判断某个行号在第几行？
 */

int Cannonball(int height) {
	// Simple case
	if (height == 0) return 0;

	// Recursive case
	return (getNumOfBallsInOneLine(height) +  Cannonball(height - 1));
}

int getNumOfBallsInOneLine(int height) {
	int i;
	for (i = 0; ((1 + i) * i / 2) < height; i++) {}
	return i;
}


