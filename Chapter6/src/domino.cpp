/*
 * File: domino.cpp
 * -----------------
 *  This file implements the Domino class.
 */

#include <string>
#include "error.h"
#include "domino.h"
#include "strlib.h"
using namespace std;

/* 
 * Implementation notes: Constructors
 * -----------------------------------
 *  There are two constructors for the Domino class.
 *  The default constructor creates a Domino with a (0, 0) value, the two-argument
 *  form allows you to specify a certain domino.
 *  
 *  The constructors ensure that the following invariants are maintained:
 *  	1. The dots on both side are between 0 - 6, inclusively.
 */

Domino::Domino() {
	leftDots = 0;
	rightDots = 0;
}

Domino::Domino(int x, int y) {
	if ((x < 0) || (x > 6)) error("leftDots out of bounds: " + x);
	if ((y < 0) || (y > 6)) error("rightDots out of bounds: " + y); 
	leftDots = x;
	rightDots = y;
}

/*
 * Implementation notes: Getters
 * ----------------------------------
 *  The getters return the value fo the corresponding instance variable.
 *  No setters are provided to ensure that Domino objects are immutable.
 */

int Domino::getLeftDots() {
	return leftDots;
}

int Domino::getRightDots() {
	return rightDots;
}

/*
 * Implementation notes: toString and << operator
 * ----------------------------------
 *  The implementation of toString uses the integerToString function from the strlib.h
 *  interface.
 *  The overload of << operator.
 */
string Domino::toString() {
	return "(" + integerToString(leftDots) + ", " + integerToString(rightDots) + ")";
}

ostream & operator<<(ostream & os, Domino dmo) {
	return os << dmo.toString();
}

/*
 * Implementation notes: Boolean operators
 * ----------------------------------------
 * The implementation of the operators follows directily from the definitions.
 */

bool operator==(Domino dmo1, Domino dmo2) {
	return ((dmo1.leftDots == dmo2.leftDots) && (dmo1.rightDots == dmo2.rightDots)) || 
		((dmo1.leftDots == dmo2.rightDots) && (dmo1.rightDots == dmo2.leftDots));
}

bool operator!=(Domino dmo1, Domino dmo2) {
	return !(dmo1 == dmo2);
}
