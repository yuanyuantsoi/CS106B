/*
 * File: TestCalendar.cpp
 * ----------------------------
 *  This program is user to test calendar lib
 */

#include "calendar.h"
#include "simpio.h"
#include <iostream>
using namespace std;

int main() {
	int year = getInteger("Enter a year: ");
	for (int i = 1; i <= 12; i++) {
		Month month = Month (i);
		int days = daysInMonth(month, year);
		cout << monthToString(month) << " has " << days << " days." << endl;
	}
	return 0;
}
	
