/*
 * File: ex06.cpp
 * ----------------------------------------------------
 *  This program imepments the "sieve of Eraosthenes" to generate
 *  a list of primes between 2 and 1000.
 */
#include <iomanip>
#include "vector.h"
#include <iostream>
#include <string>
using namespace std;

void crossOffMultipleOfCircledNum(Vector<int> & numList, int & circledIndex);
void printVector(Vector<int> data);

int main() {
	Vector<int> data;
	for (int i = 2; i <= 1000; i++) {
		data.add(i);
	}
	int circledIndex = 0;
	while (circledIndex < (data.size() - 1)) {
		crossOffMultipleOfCircledNum(data, circledIndex);
		circledIndex++;
	}
	printVector(data);
	return 0;
}

void crossOffMultipleOfCircledNum(Vector<int> & numList, int & circledIndex) {
	for (int i = numList.size() - 1; i > circledIndex; i--) {
		if (numList[i] % numList[circledIndex] == 0) numList.remove(i);
	}
	return;
}

void printVector(Vector<int> data) {
	for (int i = 0; i < data.size(); i++) {
		cout << setw(4) << data[i];
		if (i % 10 == 9) cout << endl;
	}
	cout << endl;
	return;
}
