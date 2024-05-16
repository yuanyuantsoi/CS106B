/*
 * File: calendar.cpp
 * -----------------------------
 *  CS106B - ex11
 *  
 *  This file implements calendar.h interface
 */
#include "calendar.h"
#include <string>
using namespace std;

/*
 * Implementation notes: daysInMonth
 * ----------------------------------
 *  Return the number of days in that month of the year.
 */

int daysInMonth(Month month, int year) {
	switch (month) {
		case APRIL:
		case JUNE:
		case SEPTEMBER:
		case NOVEMBER:
			return 30;
		case FEBRUARY:
			return (isLeapYear(year)) ? 29 : 28;
		default:
			return 31;
	}
}


/*
 * Implementation notes: isLeapYear
 * ------------------------------------
 *  A leap year is any year divisible by 4, except for years ending in 00, 
 *  in which case the year must be divisible by 400.
 */

bool isLeapYear(int year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}



/*
 * Implementation notes: monthToString
 * -----------------------------------
 *  The C++ complier requires the default clause to ensure that this function
 *  always returns a string, even if the direction is not one of the legal value.
 */

string monthToString(Month month) {
	switch (month) {
		case JANUARY: return "JANUARY";
		case FEBRUARY: return "FEBRUARY";
		case MARCH: return "MARCH";
		case APRIL: return "APRIL";
		case MAY: return "MAY";
		case JUNE: return "JUNE";
		case JULY: return "JULY";
		case AUGUST: return "AUGUST";
		case SEPTEMBER: return "SEPTEMBER";
		case OCTOBER: return "OCTOBER";
		case NOVEMBER: return "NOVEMBER";
		case DECEMBER: return "DECEMBER";
		default: return "???";
	}
}
