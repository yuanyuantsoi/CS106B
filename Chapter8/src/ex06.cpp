/*
 * File: ex06.cpp
 * ---------------------------------------------------
 *  The program implements the isMeasurable function.
 */

#include <iostream>
#include "vector.h"
using namespace std;

/* Function prototypes */

bool isMeasurable(int target, Vector<int> & weights);

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
		cout << "isMeasurable(" << i << ", sampleWeights) = " << isMeasurable(i, sampleWeights) << endl;
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

bool isMeasurable(int target, Vector<int> & weights) {
	if (weights.isEmpty()) {
		return target == 0;
	} else {
		int first = weights[0];
		Vector<int> rest = weights;
		rest.remove(0);
		return isMeasurable(target - first, rest) || isMeasurable(target + first, rest)
			|| isMeasurable(target, rest);
	}
}


