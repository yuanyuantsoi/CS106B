/*
 * File: ex12.cpp
 * -----------------------------
 *  The RandomAverage function repeatedly generates
 *  a random real number between 0 and 1 and then displays the average after a 
 *  specified number of trials entered by the user.
 */
#include <iostream>
#include "random.h"
#include "simpio.h"
using namespace std;

/* Function prototypes */
double RandomAverage(int num);

/* Main function */
int main() {
	int n = getReal("Enter num of trials: ");
	cout << "Average = " << RandomAverage(n) << endl;
	return 0;
}


double RandomAverage(int num) {
	double total = 0;
	for (int i = 0; i < num; i++) {
		total += randomReal(0, 1);
	}
	return total / num;
}
