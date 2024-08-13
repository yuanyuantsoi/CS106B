/*
 * File: ex01.cpp
 * ----------------
 *  P50
 *  ex01
 * This program reads in a temperature in degrees Celsius and displays the corresponding temperature 
 * in degrees Fahrenheit.
 */

#include <iostream>
#include "simpio.h"
using namespace std;

int main() {
	double ce = getReal("Input Celsius degrees: ");
        double fa = ce * 9 / 5 + 32;
	cout << "Corresponding temperature: " << fa << endl;
	return 0;
}	
