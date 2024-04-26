/*
 * File: Quadratic.cpp
 * -------------------
 *  This program finds roots of the quadratic equation
 *  a x^2 + b x + c = 0
 *  If a is 0 or if the equation has no real roots, the program
 *  prints an error message and exits.
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

/* Function Prototypes */

void getCoefficients(double & a, double & b, double & c);
void solveQuadratic(double a, double b, double c, double & x1, double & x2);
void printRoots(double & x1, double & x2);
void error(string msg);


void printCoe(double a, double b, double c, double x1, double x2) {
	cout << "Debug: " << endl;
	cout << "-----------------" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
	cout << "-------------------" << endl;
}

/* Main program */

int main() {
	double a, b, c, x1, x2;
	getCoefficients(a, b, c);
	solveQuadratic(a, b, c, x1, x2);
	printRoots(x1, x2);
	printCoe(a, b, c, x1, x2);
	return 0;
}



/*
 * Function: getCoefficients
 * Usage: getCoefficients(a, b, c);
 * -------------------------------
 *  Reads the coefficients of a quadratic equation into the 
 *  reference parameters a, b, and c.
 */

void getCoefficients(double & a, double & b, double & c) {
	cout << "Enter coefficients for the quadratic equation: " << endl;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
}

/*
 * Function: solveQuadratic
 * Usage: solveQuadratic(double a, double b, double c, double & x1, double & x2);
 * ----------------------------------------------------------------------------
 *  Solves a quadratic equation for the coefficients a, b, and c. The roots are returned 
 *  in the reference parameters x1 and x2.
 */

void solveQuadratic(double a, double b, double c, double & x1, double & x2) {
	if(a == 0) error("The coefficient a must be nonzero");
	double disc = b * b - 4 * a * c;
	if (disc < 0) error("This equation has no real roots.");
	double sqrtDisc = sqrt(disc);
	x1 = (- b - sqrtDisc) / (2 * a);
	x2 = (- b + sqrtDisc) / (2 * a);
}



/*
 * Function: printRoots
 * Usage: printRoots(double & x1, double & x2);
 * ---------------------------------------------
 *  This program prints the roots to the quadratic equation.
 */

void printRoots(double & x1, double & x2) {
	if (x1 == x2) {
		cout << "There is a double root at " << x1 << endl;
	} else {
		cout << "The roots are " << x1 << " and " << x2 << endl;
	}
	return;
}


/*
 * Function: error
 * Usage:error(string msg)
 * -----------------------
 *  Writes the string msg to the cerr stream and then exits the program 
 *  with a standard status value indicating that a failure has occurred.
 */

void error(string msg) {
	cerr << msg << endl;
	exit(EXIT_FAILURE);
}


