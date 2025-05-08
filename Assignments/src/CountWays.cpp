/*
 * File: CountWays.cpp
 * -----------------------------
 *  The program count the number of ways to climb
 *  the entrie staircase based on different combinations
 *  of large and small strides.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "vector.h"
#include "simpio.h"
using namespace std;

/* Function prototypes */

int countWays(int numStairs);
bool recCountWays(Vector<string> & soFar, int rest, int & count);
void recCountWays1(Vector<string> & soFar, int rest, int & count);  // It's actually an exhaustive problem(have to explore every possible options), no need to return bool under this situtaion.
void printPaths(Vector<string> & soFar);

/* Main program */

int main() {
	int n = getInteger("Enter the num of stairs = ");
	int c = countWays(n);
	cout << "There are " << c << " ways to climb the entire staircase." << endl;
	return 0;
}


/* 
 * Function: countWays
 * Usage: int n = countWays(numStairs);
 * -----------------------------------------
 *  Warpper function for recCountWays.
 */
int countWays(int numStairs) {
	int numPaths = 0;
	Vector<string> soFar;
	recCountWays1(soFar, numStairs, numPaths);
	return numPaths;
}


/*
 * Function: recCountWays
 * Usage: if(recCountWays(soFar, rest, count))
 * ---------------------------------------------
 *  The function takes the number of stairs left and the num of ways to climb the stairs,
 *  return a boolean value which indicates whether or not we found a successful arrangement
 *  starting from the beginning of stairs.
 *
 *  Base case: 	
 *  		if there are no more stairs, we have succeeded!
 *  		if the num of stairs < 0 indicatating that we took a wrong stride.
 *  
 *  Otherwise, we take turn to take a small stride or a larget stride to climb the stairs,
 *  and use recursion to build subsets from there. If the recursion return true, then we print
 *  which stride we took to succeed.
 */
bool recCountWays(Vector<string> & soFar, int rest, int & count) {
	if (rest == 0) {
		count++;
		printPaths(soFar);
		return true;
	}
	
	if (rest < 0) return false;
/*
	bool small = recCountWays(soFar += " takes a small stride ", rest - 1, count);
	soFar.remove(soFar.size() - 1);

	bool large = recCountWays(soFar += " takes a large stride ", rest - 2, count);
	soFar.remove(soFar.size() - 1);

	return (small || large);
*/

	for (int steps = 1; steps <= 2;  steps++) {
		soFar.add(((steps == 1) ? " takes a small stride " : " takes a large stride "));
		bool result = recCountWays(soFar, rest - steps, count);
		soFar.remove(soFar.size() - 1);
	}
	//return false;
	return true;
}

	

void recCountWays1(Vector<string> & soFar, int rest, int & count) {
	if (rest == 0) {
		count++;
		printPaths(soFar);
		return;
	}
	
	if (rest < 0) return;
/*
	bool small = recCountWays(soFar += " takes a small stride ", rest - 1, count);
	soFar.remove(soFar.size() - 1);

	bool large = recCountWays(soFar += " takes a large stride ", rest - 2, count);
	soFar.remove(soFar.size() - 1);

	return (small || large);
*/

	for (int steps = 1; steps <= 2;  steps++) {
		soFar.add(((steps == 1) ? " takes a small stride " : " takes a large stride "));
		bool result = recCountWays(soFar, rest - steps, count);
		soFar.remove(soFar.size() - 1);
	}
}

	
void printPaths(Vector<string> & soFar) {
	cout << endl << "Print Path: " << endl;
	for (int i = 0; i < soFar.size(); i++) {
		cout << "\t" << i + 1 << ": " << soFar[i] << endl;
	}
	cout << endl;
}


