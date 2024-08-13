/*
 * File: ex05.cpp
 * ------------------
 *  This file tests the implementation of Date class.
 */

#include "simpio.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include "strlib.h"
#include "calendar.h"
using namespace std;

int main() {
	cout << "Default construstror: " << endl;
	Date d1;
	cout << d1 << endl;
	cout << endl;
	
	int nMonth = getInteger("Enter month in form of num: ");
	Month m = Month(nMonth);
	int day = getInteger("Enter day: ");
	int year = getInteger("Enter year: ");
	Date d2(m, day, year);
	cout << "d2: " << d2 << endl;
	cout << endl;
	
	Date d3(day, m, year);
	cout << "d3: " << d3 << endl;
	cout << endl;
	return 0;
}
