/*
 * File: ex16.cpp
 * -----------------------
 *  This program uses the graphics library to draw a rainbow
 *  with six bands. The color of each bands are red, yellow, 
 *  green, and magenta. The sky of the color is cyan.
 */

#include "gwindow.h"
#include "gobjects.h"
#include <iostream>
using namespace std;

void drawRainbowBand(GWindow & gw, double cenX, double cenY, double radius, string color);

int main() {
	GWindow gw;
	double cenX = gw.getWidth() / 2;
	double cenY = gw.getHeight() / 3 * 4;
	double radius = gw.getHeight() * 2.5;
	double dr = gw.getHeight() / 10;
	gw.setColor("CYAN");
	gw.fillRect(0, 0, gw.getWidth(), gw.getHeight());

	drawRainbowBand(gw, cenX, cenY, radius, "RED");
	drawRainbowBand(gw, cenX, cenY, radius - dr, "ORANGE");
	drawRainbowBand(gw, cenX, cenY, radius - 2 * dr, "YELLOW");
	drawRainbowBand(gw, cenX, cenY, radius - 3 * dr, "GREEN");
	drawRainbowBand(gw, cenX, cenY, radius - 4 * dr, "BLUE");
	drawRainbowBand(gw, cenX, cenY, radius - 5 * dr, "MAGENTA");
	drawRainbowBand(gw, cenX, cenY, radius - 6 * dr, "CYAN");
	return 0;
}


void drawRainbowBand(GWindow & gw, double cenX, double cenY, double radius, string color) {
	double posX = cenX - radius / 2;
	double posY = cenY - radius / 2;
	GOval *oval = new GOval(posX, posY, radius, radius);
	oval->setFilled(true);
	oval->setFillColor(color);
 	gw.add(oval);
	return;
}

