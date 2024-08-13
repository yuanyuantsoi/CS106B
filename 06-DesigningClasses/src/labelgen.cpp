/*
 * File: labelgen.cpp
 * --------------------------
 *  This file implements the LabelGenerator  class.
 */

#include <string>
#include <cstdlib>
#include <iostream>
#include "strlib.h"
#include "labelgen.h"
using namespace std;

/*
 * Implementation notes: Constructor
 * --------------------------------------
 *  The constructor take the string as the prefix, the number
 *  as the starting number.
 */

LabelGenerator::LabelGenerator(string str, int n) {
	prefix = str;
	num = n;
}

/*
 * Implementation notes: nextLabel()
 * --------------------------------------
 *  Return the string of the next label.
 */

string LabelGenerator::nextLabel(){
	string str = toString();
	num++;
	return str;
}

/* Implementation of toString and the << operator */

string LabelGenerator::toString() {
	return prefix + integerToString(num);
}

ostream & operator<<(ostream & os, LabelGenerator label) {
	return os << label.toString();
}
