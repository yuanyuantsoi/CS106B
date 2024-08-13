/*
 * File: ex16.cpp
 * -----------------------------------------
 *  The program draws the H-fractal pattern.
 */

#include <iostream>
#include <cmath>
#include "gwindow.h"
using namespace std;

/* Constants */

const double SIZE = 200;		/* Size of the order 0 fractal in pixels */
const int ORDER = 4;			/* Order of the fractal snowflake */

/* Function prototypes */

void drawHFractal(GWindow & gw, double x, double y,
				  double size, int order);

/* Main program */

int main() {
	GWindow gw;
	double xc = gw.getWidth() / 2;
	double yc = gw.getHeight() / 2;
	drawHFractal(gw, xc, yc, 100, 4);
	return 0;
}

/*
 * Function: drawHFractal
 * Usage: drawHFractal(gw, xc, yc, size, order);
 * -----------------------------------------------------
 *  The recursive function draw the H-fractal pattern.
 *  x and y are the coordinates of the center of the H-fractal,
 *  size specifies the width and the height, and order indicates the
 *  order of the fractal.
 */
void drawHFractal(GWindow & gw, double x, double y,
				  double size, int order) {
	if (order < 0) {
		return;
	} else {
		GPoint pt(x, y);
		double sideLength = size / 2;
		
		GPoint ptL = gw.drawPolarLine(pt, sideLength, 0);
	       	GPoint ptLU = gw.drawPolarLine(ptL, sideLength, 90);
		drawHFractal(gw, ptLU.getX(), ptLU.getY(), sideLength, order - 1);
		
		GPoint ptLD = gw.drawPolarLine(ptL, sideLength, - 90);
		drawHFractal(gw, ptLD.getX(), ptLD.getY(), sideLength, order - 1);

		GPoint ptR = gw.drawPolarLine(pt, sideLength, 180);
		GPoint ptRU = gw.drawPolarLine(ptR, sideLength, 90);
		drawHFractal(gw, ptRU.getX(), ptRU.getY(), sideLength, order - 1);
		
		GPoint ptRD = gw.drawPolarLine(ptR, sideLength, -90);
		drawHFractal(gw, ptRD.getX(), ptRD.getY(), sideLength, order - 1);
	}
}

