/*
 * File: ex02.cpp
 * -----------------------
 *  Reimplement the distance-conversion program.
 */

#include <iostream>
#include "simpio.h"
using namespace std;

/* Conversion factors constants */
const double INCH_TO_METERS = 0.0254;
const double FOOT_TO_INCH = 12;

/* Function prototypes */

void convertMeterToFtInch(double meter, int & foot, double & inch);



/* Main function */

int main() {
	double meter = getInteger("Enter meters = ");
	int foot = 0;
	double inch = 0;
	convertMeterToFtInch(meter, foot, inch);
	cout << meter << " m = " << foot << " ft " << inch << " inches" << endl;
	return 0;
}

void convertMeterToFtInch(double meter, int & foot, double & inch) {
	inch = meter / INCH_TO_METERS;
	foot = int (inch / FOOT_TO_INCH);
	inch = inch - foot * FOOT_TO_INCH;
	return;
}
