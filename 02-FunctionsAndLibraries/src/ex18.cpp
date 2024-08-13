/*
 * File: ex18.cpp
 * ----------------
 *  This program draw the symbol of yin-yang.
 */

#include "gwindow.h"
using namespace std;

/* Constants */
const double SIZE_WINDOW = 800;
const double RADIUS = 250;
int main() {
	GWindow gw(SIZE_WINDOW, SIZE_WINDOW);
	double radius = RADIUS;
	double cenX = gw.getWidth() / 2;
	double cenY = gw.getHeight() / 2;


	gw.setColor("BLACK");
	gw.fillOval(gw.getWidth() / 2 - radius, gw.getHeight() / 2 - radius, 2 * radius, 2 * radius);
	
	gw.setColor("WHITE");
	gw.fillRect(cenX - radius, cenY - radius, radius, 2 * radius);
	
	gw.setColor("BLACK");
	gw.drawOval(cenX - radius, cenY - radius, 2 * radius, 2 * radius);

	gw.setColor("WHITE");
	gw.fillOval(cenX - radius / 2, cenY - radius, radius, radius);

	gw.setColor("BLACK");
	gw.fillOval(cenX - radius / 2, cenY, radius, radius);

	gw.setColor("BLACK");
	gw.fillOval(cenX - radius / 10, cenY - radius / 2 - radius / 10, radius / 5, radius / 5);

	gw.setColor("WHITE");
	gw.fillOval(cenX - radius / 10, cenY + radius / 2 - radius / 10, radius / 5, radius / 5);
		
	return 0;
}	

