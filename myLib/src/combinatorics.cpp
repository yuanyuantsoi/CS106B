/*
 * File: combinatorics.cpp
 * --------------------------------
 *  This program contains permutations and combinations.
 */

#include "combinatorics.h"
using namespace std;

int combinations(int n, int k) {
	int ans = 1;
	for (int i = 0; i < k; i++) {
		ans = ans * (n - i) / (i + 1);
	}
	return ans;
}



int permutations(int n, int k) {
	int ans = 1;
	for (int i = n; i > (n - k); i--) {
		ans *= i;
	}
	return ans;
}
