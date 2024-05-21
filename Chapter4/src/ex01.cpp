/*
 * File: ex01.cpp
 * -----------------------------------------
 *  This program displays a table of trigonometric
 *  sines and cosines. The numeric columns should 
 *  all be aligned on the right, and the trigonometic 
 *  function have seven digits after the decimal point.
 */

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.14159265358979323846;

int main() {
	cout << " theta | sin(theta) | cos(theta) |" << endl;
	for (int theta = -90; theta <= 90; theta += 15) {
		double a = double(theta) * PI / 180;
		double sina = sin(a);
		double cosa = cos(a);
		cout << fixed << right << "  "
			<< setw(3) << theta << "  | "
			<< setw(10) << sina << " | "
			<< setw(10) << cosa << " | " << endl;
	}
	return 0;
}
		
