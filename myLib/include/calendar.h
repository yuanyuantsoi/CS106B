/*
 * File: calendar.h
 * -------------------------------
 *  This interface exports an enumerated type called Month whose
 *  elements are the 12 months
 */

#ifndef _calendar_h
#define _calendar_h

#include <string>

/*
 * Type: Month
 * ----------------
 *  This enumerated typed is used to represent the 12 month.
 */

enum Month { 
	JANUARY = 1, 
	FEBRUARY, 
	MARCH, 
	APRIL, 
	MAY, 
	JUNE, 
	JULY, 
	AUGUST, 
	SEPTEMBER, 
	OCTOBER, 
	NOVEMBER, 
	DECEMBER};

/*
 * Function: daysInMonth
 * Usage: int days = daysInMonth(month, year);
 * ----------------------------------------------
 *  Returns the num of days in that month.
 */

int daysInMonth(Month month, int year);

/*
 * Function: isLeapYear
 * Usage: bool isLeapYear(year);
 * -------------------------------------
 *  Return true if the year is leap year.
 */
bool isLeapYear(int year);


/*
 * Function: monthToString
 * Usage: string str = monthToString(month);
 * ----------------------------------------
 *  Return the name of the month as a string.
 */

std::string monthToString(Month month);

#endif
