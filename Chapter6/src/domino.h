/*
 * File: domino.h
 * ----------------
 *  This interface exports a class for representing a traditional domino.
 */

#ifndef _domino_h
#define _domino_h

#include <string>
#include <iostream>

/*
 * Class: Domino
 * --------------
 *  The Domino class is userd to represent a traditional domino, which is composed of
 *  two black rectangles with some number of white dots on each side.
 */

class Domino {
	
public:

/*
 * Constructor: Domino
 * Usage: Domino origin;
 * 	  Domino dmo(x, y);
 * -----------------------------------
 *  Creates a Domino object. 
 *  The default constructor sets the domino tiles to (0, 0);
 *  The second form sets the left dots to x, and right dots to y.
 */
	Domino();
	Domino(int x, int y);

/*
 * Methods: getLeftDots, getRightDots
 * Usage: int lDot = dmo.getLeftDots();
 * 	  int rDot = dmo.getRightDots();
 * --------------------------------------
 *  These method return the left dots and right dots of the domino.
 */
	int getLeftDots();
	int getRightDots();


/*
 * Method: toString
 * Usage: string str = dmo.toString();
 * -----------------------------------
 *  Returns a string representation of the domino in the form of "(x, y)".
 */
	std::string toString();


/* Private Section */

private:

/* Friend declaration */
	friend bool operator==(Domino dmo1, Domino dmo2);

/* Instances variables */
	int leftDots;    
	int rightDots;
};


/*
 * Operator: <<
 * Usage: cout << dmo;
 * --------------------
 *  Overloads the << operator so that it is able to display Domino values.
 */

std::ostream & operator<<(std::ostream & os, Domino dmo);

/*
 * Operator: ==
 * Usage: dmo1 == dmo2
 * --------------------
 *  Implements the == operator for points.
 */

bool operator==(Domino dmo1, Domino dmo2);

/*
 * Operator: !=
 * Usage: dmo1 != dmo2
 * ------------------------------
 *  Implements the != operator for dominos. It is good practice to overload this 
 *  operator whenever you overload == to ensure that clients can perform either test.
 */

bool operator!=(Domino dmo1, Domino dmo2);

#endif



