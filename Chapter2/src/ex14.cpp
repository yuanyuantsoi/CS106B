/*
 * File: ex14.cpp
 * ---------------------
 *  This program simulates throwing 10,000 darts
 *  and then used the Monte Carlo integrating to 
 *  generate and display an approximate value of 
 *  pi.
 *  The simulation process:
 *  	1. the dart board is drawn on the standard
 *  	plane with its center at the origin and a 
 *  	radius of 1 unit.
 *  	2. throw a dart randomly at the square generating
 *  	two numbers, x and y, each of which lies between
 *  	-1 and + 1;
 */

#include <iostream>
#include "random.h"
#include <cmath>
using namespace std;

/* constants */
const int NUM_DARTS = 100000;

/* Main function */
int main() {
	int inCircle = 0;
	for (int i = 0; i < NUM_DARTS; i++) {
		double x = randomReal(-1, 1);
		double y = randomReal(-1, 1);
		if ((pow(x, 2) + pow(y, 2)) < 1) inCircle++;
	}
	double pi = double(inCircle) / NUM_DARTS * 4;
	cout << "pi = " << pi << endl;
	return 0;
}
