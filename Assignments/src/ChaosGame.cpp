/*
 * File: ChaosGame.cpp
 * -----------------------
 *  CS106B - Handout #9 (Jan 14, 2008)
 *  Chaos Games steps:
 *  	1. Create a window  -  Gwindow dw;
 *  	2. prompt the user for three points inside the window - GEvent & Gtypes
 *  	3. connect the three points - GLine
 *  	4. randomly choose one point of these three -- random.h
 *  	5. draw a small circle around the point -- GObject.h
 *  	6. choose one vertex and move the current point half of the distance -- findMidPoint
 *  	7. repeat steps 5 & 6 (stop when the user clicks the mouse)
 */

#include <iostream>
#include "gwindow.h"
#include "gevents.h"
#include "gobjects.h"
#include "random.h"
#include "gtypes.h"
#include "error.h"
#include "vector.h"
using namespace std;

const int RADIUS = 10;
const string COLOR = "BLUE";

/* Function prototype */
GPoint selectPoint(GWindow & gw, string prompt = "");
GPoint chooseRandomVertex(Vector<GPoint> vetx);
void addFilledCircle(GWindow & gw, GPoint center, double radius);

/* Main Program */

int main() {
	GWindow gw;
	cout << "This program demostrate the chaos game." << endl;
	
	// Get point A, B, C
	GPoint A = selectPoint(gw," Click the window to select point A");
	GPoint B = selectPoint(gw, "Click the window to select point B");
	GPoint C = selectPoint(gw, "Click the window to select point C");
	
	// Conect the points
	gw.add(new GLine(A.getX(), A.getY(), B.getX(), B.getY()));
	gw.add(new GLine(A.getX(), A.getY(), C.getX(), C.getY()));
	gw.add(new GLine(B.getX(), B.getY(), C.getX(), C.getY()));
	
	// Construct a vertex vector
	Vector<GPoint> vetx;
	vetx.add(A);
	vetx.add(B);
	vetx.add(C);

	// Choose start point 
	GPoint currentPt = chooseRandomVertex(vetx);

	while (true) {
		addFilledCircle(gw, currentPt, RADIUS);

		// Choose end point
		GPoint end = chooseRandomVertex(vetx);
		
		// Find middle point
		GPoint middle((end.getX() + currentPt.getX()) / 2, (end.getY() + currentPt.getY()) / 2);

		currentPt = middle;
	}
	return 0;
}



/*
 * Method: selectPoint
 * Usage: GPoint pt = selectPoint(& gw, prompt);
 * -------------------------------------
 *  Select a point in the destiganti window and return the point.
 */
GPoint selectPoint(GWindow & gw, string prompt) {
	cout << prompt << endl;
	while (true) {
		GMouseEvent e = waitForEvent();
		if (e.getEventType() == MOUSE_CLICKED) {
			GPoint pt(e.getX(), e.getY());
			cout << "The point is in " << pt.toString() << endl;
			return pt;
		}
	}
}



/*
 * Function: chooseRandomVertex
 * Usage: GPoint pt = chooseRandomVertex();
 * ---------------------------------------
 * Choose random vertex between A, B, C
 */

GPoint chooseRandomVertex(Vector<GPoint> vetx) {
	int randInt = randomInteger(0, vetx.size() - 1);
	return vetx[randInt];
}



/*
 * Function: addFilledCircle
 * Usage: void addFilledCircle(GWindow, center, radius);
 * ----------------------------------------------
 *  Adds a filled circle to the GWindow.
 */

void addFilledCircle(GWindow & gw, GPoint center, double radius) {
	GOval *oval = new GOval(center.getX() - radius / 2, center.getY() - radius / 2, radius, radius);
	oval->setFilled(true);
	oval->setColor(COLOR);
	gw.add(oval);
	return;
}
