/*
 * File: ex13.cpp
 * -------------------------------
 *  The program simulates the decay of a sample that contains
 *  10,000 atoms of radioactive material, where each atom has a 50 percent chance
 *  of decaying in a year. The output of the program shows the number
 *  of atoms remainning at the end of each year.
 */

#include <iostream>
#include "random.h"
using namespace std;

/* constants */
const int TOTAL_NUM_ATOMS = 10000;

/* Function prototypes */
int AtomDecay(int n);

/* Main function */
int main() {
	int num = TOTAL_NUM_ATOMS;
	cout << "There are " << num << " atoms initially." << endl;
	int year = 0;
	while (num != 0) {
		year++;
		num = AtomDecay(num);
		cout << "There are " << num << " atoms at the end of year " << year << endl;
	}
	return 0;
}

int AtomDecay(int n) {
	int left = n;
	for (int i = 0; i < n; i++) {
		if (randomChance(0.5)) left--;
	}
	return left;
}
		
