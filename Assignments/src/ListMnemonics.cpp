/*
 * File: ListMnemonics.cpp
 * -------------------------------
 *  H17.sectionhanout#3 -- Chapter08.ex10
 */

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include "map.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Function prototypes */

void ListMnemonics(string str);

/* Main program */

int main() {
	string number = getLine("Enter number: ");
	ListMnemonics(number);
	return 0;
}

/*
 * Function: ListMnemonics
 * Usage: ListMnemonics(str);
 * -----------------------------------
 *  The function generates all possible letter
 *  combinations that correspond to a given number,
 *  represented as a string of digits.
 */

void ListMnemonics(string str) {
}
