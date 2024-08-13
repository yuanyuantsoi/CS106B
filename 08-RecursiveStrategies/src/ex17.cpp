/*
 * File: ex17.cpp
 * ------------------------------------
 *  The program draws the fractal tree.
 *
 * 参考GITHUB - zenglenn42
 */
#include <iostream>
#include <cmath>
#include "gwindow.h"
using namespace std;

/* Constants */

const int SPLIT_ANGLE = 45;   /* The angle between two branches are 2 * SPLIT_ANGLE */
const int TRUNCK_LENGTH = 100;

/* Function prototypes */

void drawFractalTree(GWindow & gw, GPoint pt, double size, int order);
GPoint drawTrunk(GWindow & gw, GPoint pt, double length, int theta);
void drawBranches(GWindow & gw, GPoint pt, double size, int order, int orientation);

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
	int theta = 90;
	pt = drawTrunk(gw, pt, size, theta);
	// Draw Branches
	drawBranches(gw, pt, size, order, 90);
}

/*
 * Function: drawTrunk
 * Usage: GPoint pt = drawTrunk(gw, pt, length, theta);
 * ----------------------------------------------------------------
 *  The function draws the main trunk of the fractaltree, the height of which
 *  is specified by the length. The start point specified by the pt.
 *  And theta specifies the angle between the x axis and trunk.
 */

GPoint drawTrunk(GWindow & gw, GPoint pt, double length, int theta) {
	return gw.drawPolarLine(pt, length, theta);
}

void drawBranches(GWindow & gw, GPoint pt, double size, int order, int orientation) {
	if (order != 0) {
		int angleR = orientation - SPLIT_ANGLE;
		int angleL = orientation + SPLIT_ANGLE;
		GPoint ptL = gw.drawPolarLine(pt, size, angleL);
		GPoint ptR = gw.drawPolarLine(pt, size, angleR);
		drawBranches(gw, ptL, size / 2, order - 1, angleL);
		drawBranches(gw, ptR, size / 2, order - 1, angleR);
	}
}
