/*
 * File: labelgen.h
 * -----------------
 *  This interface exports a class for generating labels.
 */

#ifndef _labelgen_h
#define _labelgen_h

#include <iostream>
#include <string>

/*
 * Class: LabelGenerator
 * ------------------------
 *  The LabelGenerator class is used to generate labels, which are
 *  defined to be concation of prefix string and number.
 */

class LabelGenerator {

public:

/*
 * Constructor: LabelGenerator
 * Usage: LabelGenerator label("Figure ", 1);
 * --------------------------------------------
 *  Creates a LabelGenerator object. The constructor creates a label
 *  with the string as the prefix, the number as the starting number.
 */
	LabelGenerator(std::string str, int n);

/*
 * Method: toString() 
 * Usage: string str = label.toString();
 * ---------------------------------------
 *  Returns the string representation of this label.
 */
	std::string toString();

/*
 * Method: nextLabel()
 * Usage: string str = label.nextLabel();
 * -----------------------------------------------------
 *  Return the string of the next label.
 */
	std::string nextLabel(); 

/* private section */

private:

/* Instance variables */
	std::string prefix;
	int num;
};

/*
 * Operator: <<
 * ---------------
 *  Overloads the << operator so that it is able to display label values.
 */
	std::ostream & operator<<(std::ostream & os, LabelGenerator label);

#endif



