/*
 * File: ex13.cpp
 * ----------------------------------
 * This program creates a line drawing in a style reminiscent
 * of Mondrian.
 */

#include <iostream>
#include "gwindow.h"
#include "random.h"
#include "strlib.h"
using namespace std;

/* Constants */

const double MIN_AREA = 10000; /* Smallext dquare that will be split. */
const double MIN_EDGE = 20; /* Smallest edge length allowed */

/* Function prototypes */

void subdivideCanvas(GWindow & gw, double x, double y, double width, double height);
string getRandomColor();

/* Main program */

int main() {
	GWindow gw;
	subdivideCanvas(gw, 0, 0, gw.getWidth(), gw.getHeight());
	return 0;
}

/*
 * Function: subdivideCanvas
 * Usage: subdivideCanvas(gw, x, y, width, height);
 * -------------------------------------------------------------
 *  Decomposes the specified rectangular region on the canvas recursively by
 *  spliting that rectangle randomly along its larger dimension.
 *  The recursion continues untiol the area falls below the constant MIN_AREA.
 */

void subdivideCanvas(GWindow & gw, double x, double y, double width, double height) {
	if (width * height >= MIN_AREA) {
		gw.setColor(getRandomColor());
		gw.fillRect(x, y, width, height);
		gw.setColor("black");
		if (width > height) {
			double mid = randomReal(MIN_EDGE, width - MIN_EDGE);
			subdivideCanvas(gw, x, y, mid, height);
			subdivideCanvas(gw, x + mid, y, width - mid, height);
			gw.drawLine(x + mid, y, x + mid, y + height);
		} else {
			double mid = randomReal(MIN_EDGE, height - MIN_EDGE);
			subdivideCanvas(gw, x, y, width, mid);
			subdivideCanvas(gw, x, y + mid, width, height - mid);
			gw.drawLine(x, y + mid, x + width, y + mid);
		}
	}
}

/*
 * Function: getRandomColor
 * Usage: string color = getRandomColor();
 * ------------------------------------------
 *  Return random color.
 */

string getRandomColor() {
	switch (randomInteger(0, 7)) {
			case 0: return "black";
			case 1: return "blue";
			case 2: return "yellow";
			case 3: return "red";
			case 4: return "white";
			case 5: return "white";
			case 6: return "gray";
			case 7: return "light gray";
			default: return "ERROR";
	}
}
