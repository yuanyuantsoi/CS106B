/*
 * File: calendar.h
 * -------------------------------
 *  This interface exports an enumerated type called Month whose
 *  elements are the 12 months
 *  Chapter6-ex5 Exports a Date class.
 */

#ifndef _calendar_h
#define _calendar_h

#include <string>
#include <iostream>
#include <cstdlib>

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


class Date {

public:

/*
 * Function: Constructors
 * Usage: Date date();
 *        Date date(month, day, year);
 *        Date date(day, month, year);
 * ------------------------------------------
 *  There are three constructors.
 *  	1. The default constructor that sets the date to January 1, 1900.
 *  	2. The second constructor that takes a month, day and year and intializes
 *  	the date to contain those values. For ex: Date moonLanding(JULY, 20, 1969).
 *  	3. An overloaded version of the constructor that takes the first two parameters
 *  	in the opposite order. Ex: Date moonLanding(20, JULY, 1969).
 */

	Date();
	Date(Month myMonth, int myDay, int myYear);
	Date(int myDay, Month myMonth, int myYear);

/*
 * Function: Getters
 * Usage: int num = date.getDay();
 * 	  string str = date.getMonth();
 * 	  int num = date.getYear();
 * ----------------------------------------
 *  Return the day, month and year.
 */
	int getDay();
	Month getMonth();
	int getYear();

/*
 * Fucntion: toString
 * Usage: string str = date.toString()
 * --------------------------------------
 *  Return the date in the form of dd-mmm-yyyy.
 */
	std::string toString();


/* Declare the relational operator functions as friends */

	friend bool operator==(Date d1, Date d2);
	friend bool operator<(Date d1, Date d2);

/* Declare the arithmethic operator functions as friends */
	friend Date operator+(Date date, int n);
	friend Date operator-(Date date, int n);

/* Private section */

private:

	/* Instance variables */

	int day;
	Month month;
	int year;



};

/*
 * Function: Overload operator<<
 * Usage: cout << date;
 * ------------------------------
 *  Overload the operator << to use the simplied version 
 *  of cout << date.toString();
 */

std::ostream & operator<<(std::ostream & os, Date d);


/*
 * Function: relational operators ==, !=, <, <=, > and >=
 * Usage: if (date1 == date2)
 *        if (date1 != date2)
 *        if (date1 < date2)
 *        if (date1 <= date2)
 *        if (date1 > date2)
 *        if (date1 >= date2)
 * -------------------------------------------------------------
 *  Overload the relational operators.
 */

bool operator==(Date d1, Date d2);
bool operator!=(Date d1, Date d2);
bool operator<(Date d1, Date d2);
bool operator<=(Date d1, Date d2);
bool operator>(Date d1, Date d2);
bool operator>=(Date d1, Date d2);

/*
 * Operator: +
 * Usage: date = date + n
 * --------------------------------------------
 * Overloads the + operator returns the date n days after date.
 */
Date operator+(Date date, int n);

/*
 * Operator: -
 * Usage: date = date - n
 * --------------------------------------------
 *  Return the date n days before date.
 */
Date operator-(Date date, int n);

/*
 * Operator: -
 * Usage: int n = d1 - d2
 * ---------------------------------------------
 *  Returns how many dasy separate d1 and d2.
 */
int operator-(Date d1, Date d2);

/*
 * Operator: +=, -=
 * Usage: date += n 
 *        date -= n
 * ----------------------------------------------
 *  date += n shorthand for date = date + n;
 *  date -= n shorthand for date = date - n;
 */
Date operator+=(Date & date, int n);
Date operator-=(Date & date, int n);

/*
 * Operator: ++ 
 * Usage: date++, ++date
 * -----------------------------------------------
 * date++ shorthand for date = date + 1, returns the number date before incrementation.
 * ++date shorthand for date = date + 1, returns the number date after incrementation.
 */
Date operator++(Date & date);
Date operator++(Date & date, int);

/*
 * Operator: --
 * Usage: date--, --date
 * ------------------------------------------------
 *  date-- shorthand for date = date - 1, return the number date before decrementation.
 *  --date shorthand for date = date - 1, returns the number date after decrementation.
 */
Date operator--(Date & date);
Date operator--(Date & date, int);

#endif
