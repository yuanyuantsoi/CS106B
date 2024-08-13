/*
 * File: ex02.cpp
 * -----------------------
 *  This program converts a distance in meters to the corresponding 
 *  English distance in feet and inches.
 *
 *  The conversion factors:
 *  	1 inch = 0.0254 meters
 *  	1 foot = 12 inches
 */

#include  <iostream>
#include "simpio.h"
#include <string>
using namespace std;

/* Conversion factors Constants */
const double INCH_TO_METER = 0.0254;
const double FOOT_TO_INCH = 12;



int main() {
	double meter = getReal("Input distance in meters: "); 
	double inch = meter / INCH_TO_METER;
	int foot = int  (inch / FOOT_TO_INCH);
	inch = inch - foot * FOOT_TO_INCH;
	if (foot > 0) {
		cout << meter << " m = " << foot << " feet " << inch << " inches" << endl;
	} else {
		cout << meter << " m = " << inch << " inches" << endl;
	}
	return 0;
}
