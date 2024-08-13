/*
 * File: ex08.cpp
 * ------------------------
 *  The program reads in an integer and then displays the number that 
 *  has the same digits in the reverse order.
 */

#include <iostream>
#include "simpio.h"
using namespace std;

int main () {
	cout << "The program reverses the digits in an integer. " << endl;
	int n = getInteger("Enter a positive integer: ");
	int rvsN = 0;
	while (n > 0) {
		rvsN = rvsN * 10 + n % 10;
		n /= 10;
	}
	cout << "The reversed integer is " << rvsN << endl;
	return 0;
}

