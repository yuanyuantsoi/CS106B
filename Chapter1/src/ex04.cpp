/*
 * File: ex04.cpp
 * ---------------
 *  The program reads in a positive integer N 
 *  and then calculates and displays the sum of the first
 *  N odd integers.
 */

#include <iostream>
#include "simpio.h"
using namespace std;

int main() {
	int N = getInteger("Input integer N = ");
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += 2 * i + 1;
	}
	cout << "The sum is " << sum << endl;
	return 0;
}
