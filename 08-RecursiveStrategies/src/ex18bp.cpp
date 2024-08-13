/*
 * File: ex18.cpp
 * -------------------------------------------
 *  The program draws the Sierpinski triangle.
 */

#include <iostream>
#include "gwindow.h"
using namespace std;

/* Function prototypes */

void drawSierpinskiTriangle(GWindow & gw, GPoint ptA, GPoint ptB, GPoint ptC, double sideLength, int order);

/* Main program */

int main() {
	GWindow gw;
	double sideLength = 200;
	int gap = 10;
	GPoint ptA(gw.getWidth() / 2, gap);
	GPoint ptB(gw.getWidth() / 2 - sideLength / 2, gap + sideLength / 2 * 1.73);
	GPoint ptC(gw.getWidth() / 2 + sideLength / 2, gap + sideLength / 2 * 1.73);
	drawSierpinskiTriangle(gw, ptA, ptB, ptC, sideLength, 8);
	return 0;
}

/*
 * Function: drawSierpinskiTriangle
 * Usage: drawSierpinskiTriangle(gw, ptA, ptB, ptC, sideLength, order);
 * ----------------------------------------------------------------------
 */

void drawSierpinskiTriangle(GWindow & gw, GPoint ptA, GPoint ptB, GPoint ptC,
						double sideLength, int order) {
	if (order == 0) {
		gw.drawLine(ptA, ptB);
		gw.drawLine(ptB, ptC);
		gw.drawLine(ptA, ptC);
	} else {
		GPoint midAB((ptA.getX() + ptB.getX()) / 2, (ptA.getY() + ptB.getY()) / 2);
		GPoint midAC((ptA.getX() + ptC.getX()) / 2, (ptA.getY() + ptC.getY()) / 2);
		GPoint midBC((ptB.getX() + ptC.getX()) / 2, (ptB.getY() + ptC.getY()) / 2);
		drawSierpinskiTriangle(gw, ptA, midAC, midAB, sideLength / 2, order - 1);
		drawSierpinskiTriangle(gw, midAB, ptB, midBC, sideLength / 2, order - 1);
		drawSierpinskiTriangle(gw, ptC, midAC, midBC, sideLength / 2, order - 1);
	}
}
