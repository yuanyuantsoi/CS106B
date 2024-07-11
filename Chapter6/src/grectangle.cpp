/*
 * File: grectangle.cpp
 * ---------------------
 *  This file implements the GRectangle class imported by the grectangle.h.
 */

#include <string>
#include <cstdlib>
#include <iostream>
#include "gtypes.h"
using namespace std;

/*
 * Implementation notes: Constructors
 * -----------------------------------
 *  There are two constructors for the GRectangle class.
 *  The default constructor creates a GRectangle with its fields set to be zero.
 *  The second constructor will need to specify the coordinate of the upper left 
 *  corner and width, height of the rectangle.
 *
 *  The invariants of the rectangle:
 *    1. width and height is always positive.
 */

GRectangle::GRectangle() {
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

GRectangle::GRectangle(double xp, double yp, double widthp, double heightp) {
	x = xp;
	y = yp;
	width = widthp;
	height = heightp;
}


/*
 * Implementation notes: contains(pt)
 * 			 contains(px, py)
 * ----------------------------------------
 *  There are two contains method for the GRectangle class.
 *  The first take a GPoint object as the parameter.
 *  The second takes x and y as the parameter.
 */
 
bool GRectangle::contains(GPoint pt) {
	return contains(pt.x, pt.y);
}

bool GRectangle::contains(double px, double py) {
	if ((px < x) || (px > (x + width))) return false;
	if ((py < y) || (py > (y + height))) return false;
	return true;
}

/*
 * Implementation notes: Getters
 * ----------------------------------
 *  The getters return the value of the corresponding instance variable.
 *  No setters are provided to ensure that GRectangle objects are immutable.
 */

double GRectangle::getX() {
	return x;
}

double GRectangle::getY() {
	return y;
}

double GRectangle::getWidth() {
	return width;
}

double GRectangle::getHeight() {
	return height;
}

/*
 * Implementation notes: isEmpty
 * ---------------------------------
 *  The rectangle is empty if the width or height is zero.
 */

bool GRectangle::isEmpty() {
	return ((width == 0) || (height == 0));
}

/*
 * Implementation notes: toString
 * -------------------------------
 *  Return the string in the form "(x, y, width, rectangle)";
 */

string GRectangle::toString() {
	return "(" + x + ", " + y + ", " + width + ", " + height + ") ";
}


