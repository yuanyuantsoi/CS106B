/*
 * File: ex15.cpp
 * -----------------------------------
 *  The program implements the drawFractalCoastline function.
 */

#include <iostream>
#include <cmath>
#include "gwindow.h"
#include "random.h"
using namespace std;

/* Constants */

const double SIZE = 200; 	/* Size of the order 0 fractal in pixels */
const int ORDER = 4;		/* Order of the fractal snowflake */

/* Function prototypes */

GPoint drawFractalCoastline(GWindow & gw, GPoint pt, 
		double r, double theta, int order);

/* Main program */

int main() {
	GWindow gw;
	cout << "Program to draw a fractal coast line." << endl;
	double cx = gw.getWidth() / 2;
	double cy = gw.getHeight() / 2;
	GPoint pt(cx - SIZE / 2, cy - sqrt(3.0) * SIZE / 6);
	pt = drawFractalCoastline(gw, pt, SIZE, 0, ORDER);
	return 0;
}

/*
 * Function: drawFractalCoastline
 * Usage: GPoint end = drawFractalCoastline(gw, pt, r, theta, order);
 * ---------------------------------------------------------------------
 *  Draws a fractal edge starting from pt and extending r units in direction theta.
 *  If order > 0, the edge is divided into four fractal edges of the next lower order.
 *  Th function returns the endpoint of the line.
 */

GPoint drawFractalCoastline(GWindow & gw, GPoint pt, 
		double r, double theta, int order) {
	if (order == 0) {
		return gw.drawPolarLine(pt, r, theta);
	} else {
		int tugAngle = randomChance(0.5) ? 60 : -60;
		pt = drawFractalCoastline(gw, pt, r / 3, theta, order - 1);
		pt = drawFractalCoastline(gw, pt, r / 3, theta + tugAngle, order - 1);
		pt = drawFractalCoastline(gw, pt, r / 3, theta - tugAngle, order - 1);
		return drawFractalCoastline(gw, pt, r / 3, theta, order - 1);
	}
}
