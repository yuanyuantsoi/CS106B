/*
 * File: ex03.cpp
 * ---------------------
 *  This file implements the function getTitiusBodeDistance(k).
 *  The main program displays the distances to each of these planets 
 *  in tabular form.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "strlib.h"
using namespace std;

/*
 * Constant: TABULAR_WIDTH
 * ------------------------------
 *  Defines the width of the tabular form.
 */
const int TABULAR_WIDTH = 7;
const int PREC = 1;

string getPlanet(int i);
double getTitiusBodeDistance(int k);
int getSubsequentElement(int k);


int main() {
	for (int i = 1; i < 9; i++) {
		cout << left << setw(TABULAR_WIDTH) << getPlanet(i)
			<< right << setw(TABULAR_WIDTH) << setprecision(PREC) << fixed
			<< getTitiusBodeDistance(i) << "AU" << endl;
	}
	return 0;
}

/*
 * Function: getPlanet
 * Usage: string str = getPlanet(i)
 * ---------------------------------------
 *  Return the planet name of the ith planet.
 */
string getPlanet(int i) {
	switch (i) {
		case 1: return "Mercury";
		case 2: return "Venus";
		case 3: return "Earth";
		case 4: return "Mars";
		case 5: return "?";
		case 6: return "Jupiter";
		case 7: return "Saturn";
		case 8: return "Uranus";
		default: return "Planet out of index.";
	}
}

/*
 * Function: getTitusBodeDistance
 * Usage: double d = getTitusBodeDistance(k)
 * --------------------------------------------
 *  The function calculates the expected distance between the sun and
 *  the kth planet, numbering outward from Mercury starting with 1.
 */
double getTitiusBodeDistance(int k) {
	return (4.0 + getSubsequentElement(k)) / 10.0;
}

/*
 * Function: getSubsequentElement
 * Usage: int n = getSubsequentElement(k)
 * ---------------------------------------------
 *  Return the subsequent element bi.
 */

int getSubsequentElement(int k) {
	if (k == 1) return 1;
	if (k == 2) return 3;
	return 2 * getSubsequentElement(k - 1);
}


