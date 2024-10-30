/*
 * File: ex04v2.cpp
 */

#include <iostream>
#include "set.h"
using namespace std;

int countSubsetSumWays(Set<int> & set, int target);
bool recCountSubset(Set<int> & set, int target, int & count);

int main() {
	Set<int> sampleSet;
	sampleSet += 1, 3, 4, 5;

	cout << countSubsetSumWays(sampleSet, 5) << endl;
	cout << countSubsetSumWays(sampleSet, 11) << endl;
	return 0;
}


int countSubsetSumWays(Set<int> & set, int target) {
	int count = 0;
	recCountSubset(set, target, count);
	return count;
}

bool recCountSubset(Set<int> & set, int target, int & count) {
	if (set.isEmpty()) {
		if (target == 0) count++;
		return target == 0;
	}
	int element = set.first();
	Set<int> rest = set - element;
	return 	recCountSubset(rest, target - element, count)
		|| recCountSubset(rest, target, count);
}

