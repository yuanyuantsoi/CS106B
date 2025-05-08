#include <iostream>
#include "gwindow.h"
#include "gobjects.h"
using namespace std;

GPoint drawHFractal(GWindow & gw, double x, double y, double size, int order);

int main() {
	GWindow gw(1500, 800);
	double xc = gw.getWidth() / 2;
	double yc = gw.getHeight() / 2;
	drawHFractal(gw, xc, yc, 100, 3);
	return 0;
}

GPoint drawHFractal(GWindow & gw, double x, double y, double size, int order) {
	GPoint midPt(x, y);
	if (order < 0) {
		return pt;
	} else {
		GPoint leftPt = gw.drawPolarLine(gw, midPt, size / 2, 0);
		pt = gw.drawPolarLine(gw, size / 2, 90);
		drawHFractal(gw, gw.x, gw.y, size / 2, order - 1);
		pt = gw.drawPolarLine(gw, size, -90);
		drawHFractal(gw, gw.x, gw.y, size / 2, order - 1);
		pt.
		pt = gw.drawPolarLine(gw, size / 2, 0);
		
		
