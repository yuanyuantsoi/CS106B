/*
 * File: ex04.cpp
 * -----------------------------------------------------------
 *  This program implements the countSubsetSumWays function.
 */

#include <iostream>
#include "simpio.h"
#include "set.h"
using namespace std;

/* Function prototypes */

int countSubsetSumWays(Set<int> & sampleSet, int target);

/* Main program */

int main() {
	Set<int> sampleSet;
	sampleSet += 1, 3, 4, 5;
	cout << "smapleSet = {" ;
	for (int n : sampleSet) {
		if (n != sampleSet.first()) cout << ", ";
		cout << n;
	}
	cout << "}; " << endl;

	int target = getInteger("Enter target = ");
	cout << " There are " << countSubsetSumWays(sampleSet, target) 
		<< " ways to get " << target << endl;
	return 0;
}

int countSubsetSumWays(Set<int> & sampleSet, int target) {
	if (sampleSet.isEmpty()) {
		return (target == 0) ? 1 : 0;
	}else {
		Set<int> rest = sampleSet - sampleSet.first();
		return (countSubsetSumWays(rest, target) +
			countSubsetSumWays(rest, target - sampleSet.first()));
	}
}
 		
