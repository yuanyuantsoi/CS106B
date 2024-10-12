/*
 * File: IsMeasurable.cpp
 * ----------------------------------
 *  H17.SectionHandout#3 - Problem7:IsMeasurable 
 *  (Programming abstractions in c++ --Chapter08.ex06)
 *
 *  The program used the recursive functionto determine whether
 *  it is possible to measure out the desired target amount with 
 *  a given set of weights.
 */

#include <iostream>
#include "vector.h"
#include "simpio.h"
using namespace std;

/* Function prototype */

bool IsMeasurable(int target, Vector<int> & weights);

/* Main program */

int main() {
	Vector<int> sampleWeights;
	sampleWeights.add(1);
	sampleWeights.add(3);

	cout << "Measure 2 -- " << IsMeasurable(2, sampleWeights) << endl;
	cout << "Measure 5 -- " << IsMeasurable(5, sampleWeights) << endl;
	cout << "Measure 3 -- " << IsMeasurable(3, sampleWeights) << endl;
	return 0;
}

/*
 * Function: IsMeasurable
 * Usage: if(IsMeasurable(2, weights));
 * ---------------------------------------
 *  Uses recursive function to determine whether
 *  it is possible to measure out the desired amount
 *  with a given set of weights.
 */

bool IsMeasurable(int target, Vector<int> & weights) {
	if (weights.isEmpty()) {
		return target == 0;
	} else {
		Vector<int> left = weights;  //每个调用需要备份一个weights,此时就需要一个 warp function.
		int n = left[0];
		left.remove(0);
		return (IsMeasurable(target, left) 
				|| IsMeasurable(target - n, left)
				|| IsMeasurable(target + n, left));
	}
}
