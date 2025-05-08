/*
 * File: CartesianProducts.cpp
 * -------------------------------
 *  The Cartesian product of A and B, is the set
 *  of all pairs(a, b) where a is a member of set A
 *  and b is a member of setB. The pair (a, b) is called an
 *  ordered pair.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include "set.h"
#include "map.h"
using namespace std;

struct pairT {
	string first, second;
};

/* Function prototypes */

Set<pairT> CartesianProduct(Set<string> & one, Set<string> & two);
void displaySet(Set<pairT> & s);
int comparePair(pairT a, pairT b);

/* Main program */

int main() {
	Set<string> A;
	A.add("A");
	A.add("B");
	A.add("C");
	
	Set<string> B;
	B.add("X");
	B.add("Y");

	cout << "set A = " << A << endl;
	cout << "set B = " << B << endl;

	cout << "Cartesian Product of A and B: " << endl;
	Set<pairT> product(comparePair);
	product = CartesianProduct(A, B);
	displaySet(product);
	return 0;
}

/*
 * Function: displaySet
 * Usage: displaySet(set);
 * ----------------------------------
 *  Display all the entries in the set.
 */
void displaySet(Set<pairT> & s) {
	for (pairT pair : s) {
		cout << "(" << pair.first << ", " << pair.second << ")" << endl;
	}
}

/*
 * Function: CartesianProduct
 * Usage: Set<string> set = CartesianProduct(A, B);
 * ------------------------------------------------------
 * The program computes the cartesian product of two sets of 
 * strings sets.
 */

Set<pairT> CartesianProduct(Set<string> & one, Set<string> & two) {
	Set<pairT> product(comparePair);
	for (string a : one) {
		for (string b : two) {
			pairT pair = {a, b};
			product.add(pair);
		}
	}
	return product;
}


int comparePair(pairT a, pairT b) {
	if (a.first > b.first) return 1;
	if (a.first < b.first) return -1;
	else if (a.second > b.second) return 1;
	else if (a.second == b.second) return 0;
	else return -1;
}
