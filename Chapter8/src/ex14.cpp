/*
 * File: ex14.cpp
 * -------------------------------------
 *  The program draws a 1-inch line at the center 
 *  of the graphics window and draws the tick mark
 *  shown in the diagram.
 */

#include <iostream>
#include "gwindow.h"
#include "gobjects.h"
using namespace std;

/* Constants */

const double HALF_INCH_TICK = 50; 

/* Function prototypes */

void drawLine(GWindow & gw, GPoint startPt, GPoint endPt);
void drawTick(GWindow & gw, GPoint startPt, GPoint endPt, double tick, int scaleTimes);

/* Main program */

int main() {
	GWindow gw;
	GPoint startPt(gw.getWidth() / 3, gw.getHeight() / 2);
	GPoint endPt(gw.getWidth() / 3 * 2, gw.getHeight() / 2);
	drawLine(gw, startPt, endPt);
	drawTick(gw, startPt, endPt, HALF_INCH_TICK, 1);
	return 0;
}

/*
 * Function: drawLine
 * Usage: drawLine(gw, startPt, endPt);
 * --------------------------------------------------------
 *  Draws the horizontal line of 1-inch line.
 */
void drawLine(GWindow & gw, GPoint startPt, GPoint endPt) {
	gw.drawLine(startPt, endPt);
}

/*
 * Function: drawTick
 * Usage: drawTick(gw, startPt, endPt, tick, scaleTimes);
 * --------------------------------------------------------
 *  Draws the tick mark on the half-inch position, quarter
 *  inches, and eighths, and sixteenths.
 */
void drawTick(GWindow & gw, GPoint startPt, GPoint endPt, double tick, int scaleTimes) {
	if (scaleTimes == 16) {
		return;
	} else {
		scaleTimes *= 2;
		double midX = (startPt.getX() + endPt.getX()) / 2;
		double midY = (startPt.getY() + endPt.getY()) / 2;
		GPoint midPt(midX, midY);
		GPoint tickPt(midX, midY - tick);
		gw.drawLine(midPt, tickPt);
		tick /= 2;
		drawTick(gw, startPt, midPt, tick, scaleTimes);
		drawTick(gw, midPt, endPt, tick, scaleTimes);
	}
}
