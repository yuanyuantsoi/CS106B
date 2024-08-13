/*
 * File: ex17.cpp
 * -----------------
 *  The program draws a checkerboard included the
 *  red and black pieces.
 */

#include "gwindow.h"
#include "gobjects.h"
using namespace std;

void drawCheckerboard(GWindow & gw);

int main() {
	GWindow gw(800, 800);
	
	drawCheckerboard(gw);








	return 0;
}


void drawCheckerboard(GWindow & gw) {
	double unit = gw.getWidth() / 8;
	double posX = 0;
	double posY = 0;
	double radius = unit * 0.4;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			posX = i * unit;
			posY = j * unit;
			if ((i + j) % 2 != 0) {
				gw.setColor("RED");
				gw.fillRect(posX, posY, unit, unit);
				
				double cirX = posX + unit / 2 - radius;
				double cirY = posY + unit / 2 - radius;
				
				if (j < 3) {
					gw.setColor("MAGENTA");
					gw.fillOval(cirX, cirY, 2 * radius, 2 * radius);
				} else if (j > 4) {
					gw.setColor("BLACK");
					gw.fillOval(cirX, cirY, 2 * radius, 2 * radius);
				}
			}
		}
	}
	return;
}
