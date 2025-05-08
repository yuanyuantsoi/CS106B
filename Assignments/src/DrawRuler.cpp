/*
 * File: DrawRuler.cpp
 * ------------------------------
 *  The problem draw a ruler with each inch  marked off
 *  into fractions using tick marks.
 */

#include "gobjects.h"
using namespace std;

/* Constants */

const double MAX_TICK_HEIGHT = 100;
const double MIN_TICK_HEIGHT = MAX_TICK_HEIGHT / 16;

/* Function prototypes */

void drawRuler(double x, double y, double w, double h);
void recDrawRuler(GWindow & gw, double x, double y, double w, double h);
void drawTick(GWindow & gw, double startX,  double startY, double endX, double endY);

/* Main program */

int main() {
	drawRuler(500, 1000, 500, MAX_TICK_HEIGHT);
	return 0;
}


/*
 * Function: drawRuler
 * Usage: drawRuler(x, y, w, h);
 * --------------------------------------
 *  Warpper function for recDrawRuler.
 */
void drawRuler(double x, double y, double w, double h) {
	GWindow gw;
	double cw = gw.getWidth();
	double ch = gw.getHeight();
	x = cw/4;
	y = ch/4*3;
	w = cw/2;
	h = cw/10;
	gw.add(new GLine(x, y, x + w, y)); // Draw the bottom edge.
	recDrawRuler(gw, x, y, w, h);
}

/*
 * Function: recDrawRuler
 * Usage: recDrawRuler(gw, x, y, w, h);
 * ---------------------------------------
 *  Draw a ruler on canvas gw using recursive function.
 *  (x, y, w, h) gives the coordinates for a rectangele in which to draw the ruler.
 *  The (x, y) stands for the coordinates of the left-bottom corner.
 *  w is the width of the rect.
 *  h is the height of the rect.
 */
void recDrawRuler(GWindow & gw, double x, double y, double w, double h) {
	if (h < MIN_TICK_HEIGHT) {
		return;
	} else {
		drawTick(gw, x + w/2, y - h, x + w/2, y);
		recDrawRuler(gw, x, y, w/2, h/2);
		recDrawRuler(gw, x + w/2, y, w/2, h/2);
	}
}


/*
 * Function: drawTick
 * Usage: drawTick(gw, startX, startY, endX, endY);
 * -------------------------------------------------
 *  Draw a line on canvas gw, starting at (startX, startY) ending
 *  at (endX, endY);
 */
void drawTick(GWindow & gw, double startX,  double startY, double endX, double endY) {
	gw.add(new GLine(startX, startY, endX, endY));
}
