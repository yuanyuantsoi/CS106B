/*
 * File: ex06.cpp
 * ----------------
 *  This file test the implementation of the calendar.h extensions.
 *  The extension follows:
 *   	1. insertion operator <<
 *   	2. relational operator ==, !=, <, <=, > and >=
 */

#include <string>
#include <cstdlib>
#include <iostream>
#include "calendar.h"
#include "simpio.h"
using namespace std;

int main() {
	Date electionDay(6, NOVEMBER, 2012);
	Date inaugurationDay(21, JANUARY, 2013);
	cout << electionDay << endl;
	cout << inaugurationDay << endl;
	while (true) {
		int d1Day = getInteger("Enter d1.day = ");
		int d1Mon = getInteger("Enter d1.month = ");
		int d1Ye = getInteger("Enter d1.year = ");
		Date d1(d1Day, Month(d1Mon), d1Ye);
		
		cout << endl;
		cout << "d1 = " << d1 << endl;
		cout << endl;

		for (int i = 1; i <= 700; i += 100) {
			cout << "d1 + " << i << " = " << d1 + i << endl;
			cout << "d1 - " << i << " = " << d1 - i << endl;

			cout << "d1 += " << i << " = " << (d1 += i) << endl;
			cout << "d1 = " << d1 << endl;

			cout << "d1++ = " << d1++ << endl;
			cout << "d1 = " << d1 << endl;

			cout << "++d1" << " = " << ++d1 << endl;
			cout << "d1 = " << d1 << endl;
			cout << endl;		
		}
		cout << inaugurationDay - electionDay << endl;
		





		string input = getLine("Press 'Q' to quit: ");
		if (input == "Q") break;
	}
	return 0;
}
