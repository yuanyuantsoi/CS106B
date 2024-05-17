/*
 * File: ex15.cpp
 * ---------------------
 *  The program simulates flipping a coin repeatedly and continues 
 *  until three consecutive heads have been tossed.
 */

#include <iostream>
#include "simpio.h"
#include <string>
#include "random.h"
using namespace std;

int main() {
	int total = 0;
	int heads = 0;
	while (heads != 3) {
		total++;
		if (randomChance(0.5)) { // return true when filp heads
			heads++;
			cout << "heads" << endl;
		} else {
			heads = 0;
			cout << "tails" << endl;
		}
	}
	cout << "It took " << total << " flips to get 3 consecutive heads." << endl;
	return 0;
}


