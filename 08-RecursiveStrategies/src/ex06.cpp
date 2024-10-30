/*
 * File: ex06.cpp
 * ---------------------------------------------------
 *  The program implements the isMeasurable function.
 */

#include <iostream>
#include "vector.h"
using namespace std;

/* Function prototypes */

bool isMeasurable(int target, Vector<int> & weights, int index);

/* Main program */

int main() {
	Vector<int> sampleWeights;
	sampleWeights += 1, 2, 3;
	cout << "sampleWeights = {";
	for (int i = 0; i < sampleWeights.size(); i++) {
	 	cout << sampleWeights[i];
	        if (i != sampleWeights.size() - 1) cout << ", ";
	}
	cout << "};" << endl;
	
	for (int i = 0; i < 10; i++) {
		cout << "isMeasurable(" << i << ", sampleWeights) = " << isMeasurable(i, sampleWeights, 0) << endl;
	}
	return 0;
}

/*
 * Function: isMeasurable
 * Usage: if (isMeasurable(target, weights))
 * --------------------------------------------------
 * isMeasurable determines whether it is possible to 
 * measure out the desired target amount with a given
 * set of weights.
 */

bool isMeasurable(int target, Vector<int> & weights, int index) {
	if (index == weights.size()) {
		return target == 0;
	} else {
		return isMeasurable(target - weights[index], weights, index + 1) 
			|| isMeasurable(target + weights[index], weights, index + 1)
			|| isMeasurable(target, weights, index + 1);
	}
}


