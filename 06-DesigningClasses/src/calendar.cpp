/*
 * File: calendar.cpp
 * -----------------------------
 *  CS106B - ex11
 *  
 *  This file implements calendar.h interface
 */
#include "calendar.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include "strlib.h"
#include "error.h"
using namespace std;

/* Function prototypes */
bool isValidDate(int d, Month m, int y);
int daysInMonth(Month month, int year);
bool isLeapYear(int year);
string monthToString(Month month);


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


/* Implementation: Date class */

/*
 * Implementation notes: Constructors
 * ------------------------------------
 *  There are three constroctors for the Date class.
 *  The default constructor creates a date initialized to January 1, 1900.
 *  The second takes the sequence of parameter as month, day, and year.
 *  The third takes the parameters int eh following order: day, month, year.
 *  
 *  Uset isIllegalDate() to check wheather the date is valid.
 */

Date::Date() {
	month = JANUARY;
	day = 1;
	year = 1900;
}

Date::Date(Month myMonth, int myDay, int myYear) {
	month = myMonth;
	day = myDay;
	year = myYear;
	if (!isValidDate(myDay, myMonth, myYear))  error("Invalid date");
}

Date::Date(int myDay, Month myMonth, int myYear) : Date(myMonth, myDay, myYear) {};


/*
 * Implementation notes: Getters
 * ------------------------------
 *  Return the day, month, and year.
 */

int Date::getDay() {
	return day;
}

Month Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}


/*
 * Implementation notes: toString and << operator
 * ---------------------------------------------------
 *  Returns the date in the form dd-mmm-yyyy, where dd is a 
 *  one- or two-digit date, mm is the three-letter English abbreviation for the month,
 *  and yyyy is the four-digit year.
 */

string Date::toString() {
	string str = monthToString(month);
	string monthStr = str.substr(0, 1) + toLowerCase(str.substr(1, 3));
	return integerToString(day) + "-" + monthStr + "-" + integerToString(year);
}

ostream & operator<<(ostream & os, Date d) {
	return os << d.toString();
}


/*
 * Implementation notes: isIllegalDate
 * ---------------------------------
 *  Checks the date for validation.
 */

bool isValidDate(int d, Month m, int y) {
	return (m >= JANUARY) && (m <= DECEMBER) &&
		(daysInMonth(m, y) >= d);
}

/*
 * Implementation notes: relational operators
 * ---------------------------------------------
 *  The implementation of te operators follows directly from the definations.
 */

bool operator==(Date d1, Date d2) {
	return (d1.day == d2.day) && (d1.month == d2.month) 
		&& (d1.year == d2.year);
}

bool operator!=(Date d1, Date d2) {
	return !(d1 == d2);
}

bool operator<(Date d1, Date d2) {
	if (d1.year < d2.year) return true;
	if (d1.year > d2.year) return false;
	if (d1.month < d2.month) return true;
	if (d1.month > d2.month) return false;
	if (d1.day < d2.day) return true;
	return false;
}

bool operator<=(Date d1, Date d2) {
	return (d1 < d2) || (d1 == d2);
}

bool operator>(Date d1, Date d2) {
	return (!(d1 < d2) && (d1 != d2));
}

bool operator>=(Date d1, Date d2) {
	return (d1 > d2) || (d1 == d2);
}


/*
 * Implementation notes: arithmetic operators for Month type
 */
Month operator++(Month & m, int) {
	Month old = m;
	if (m == DECEMBER) {
		m = JANUARY;
	} else {
		m = Month(m + 1);
	}
	return old;
}

/*
 * Operator: --
 * Usage: month--
 * ------------------
 *  Return the month;
 */

Month operator--(Month & m, int) {
	Month old = m;
	if (m == JANUARY) {
		m = DECEMBER;
	} else {
		m = Month(m - 1);
	}
	return old;
}


/*
 * Implementation notes: arithmetic operators
 * ----------------------------------------------
 *  The implementation of the operators follows directly from the definations.
 */
Date operator+(Date date, int n) {
	if (n < 0) return date - (-n);
	for (int i = 0; i < n; i++) {
		if (date.day == daysInMonth(date.month, date.year)) {
			if (date.month == DECEMBER) date.year++;
			date.month++;
			date.day = 1;
		} else {
			date.day++;
		}
	}
	return date;
}


Date operator-(Date date, int n) {
	if (n < 0) return date + (-n);
	for (int i = 0; i < n; i++) {
		if (date.day == 1) {
			if (date.month == JANUARY) date.year--;
			date.month--;
			date.day = daysInMonth(date.month, date.year);
		} else {
			date.day--;
		}
	}
	return date;
}

int operator-(Date d1, Date d2) {
	int num = 0;
	if (d1 < d2) return (d2 - d1);
	while (d1 > d2) {
		d1 = d1 - 1;
		num++;
	}
	return num;
}

Date operator+=(Date & date, int n) {
	date = date + n;
	return date;
}

Date operator-=(Date & date, int n) {
	date = date - n;
	return date;
}

Date operator++(Date & date) {
	date = date + 1;
	return date;
}

Date operator++(Date & date, int) {
	Date old = date;
	date = date + 1;
	return old;
}

Date operator--(Date & date){
	date = date - 1;
	return date;
}

Date operator--(Date & date, int) {
	Date old = date;
	date = date - 1;
	return old;
}
