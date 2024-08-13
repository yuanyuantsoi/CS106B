/*
 * File: ex17.cpp
 * ------------------------------------
 *  The program draws the fractal tree.
 *
 *  Original structure.
 */
#include <iostream>
#include <cmath>
#include "gwindow.h"
using namespace std;

/* Constants */

const int BRANCH_TRUNK_ANGLE = 135;
const int TRUNCK_LENGTH = 100;

/* Function prototypes */

void drawFractalTree(GWindow & gw, GPoint pt, double size, int order);
void drawBranches(GWindow & gw, GPoint pt, double size, int order, int theta);

/* Main program */

int main() {
	GWindow gw;
	double xc = gw.getWidth() / 2;
	double y = gw.getHeight();
	GPoint pt(xc, y);
	drawFractalTree(gw, pt, TRUNCK_LENGTH, 8);
       return 0;
}

/*
 * Function: drawFractalTree
 * Usage: drawFractalTree(gw, pt, size, order);
 * -----------------------------------------------
 *  Draw the fractal tree. pt specifies the trunck bottom,
 *  size specifies specifies the trunk length. Branches split
 *  60 degrees from the other branch.
 */
void drawFractalTree(GWindow & gw, GPoint pt, double size, int order) {
	// Draw Main trunck
	pt = gw.drawPolarLine(pt, size, 90);
	// Draw Branches
	drawBranches(gw, pt, size, order, -90);
}

void drawBranches(GWindow & gw, GPoint pt, double size, int order, int theta) {
	if (order == 0) {
		int angleR = BRANCH_TRUNK_ANGLE + theta;
		int angleL = angleR + 2 * (180 - BRANCH_TRUNK_ANGLE);
		GPoint ptL = gw.drawPolarLine(pt, size, angleL);
		GPoint ptR = gw.drawPolarLine(pt, size, angleR);
		drawBranches(gw, pt, size / 2, order - 1, theta);
	}
}
