#include <iostream>
#include "gwindow.h"
#include "gobjects.h"
#include "random.h"
#include "simpio.h"
using namespace std;

/* Function prototypes */

GPoint drawFractal(GWindow & gw, GPoint pt, double r, double theta, int order);

int main() {
	GWindow gw(1500, 800);
	double w = gw.getWidth();
	double h = gw.getHeight();
	cout << w << endl << h << endl;
	int order = getInteger("Enter order = ");
	double r = w / 3 * 2;
	double x = (w - r) / 2;
	double y = h / 3 * 2; 
	GPoint pt(x, y); 
	drawFractal(gw, pt, r, 0, order);
	return 0;
}


GPoint drawFractal(GWindow & gw, GPoint pt, double r, double theta, int order) {
	if (order == 0) {
		return gw.drawPolarLine(pt, r, theta);
	} else {
		int invert = randomChance(0.5) ? 1 : -1;
		pt = drawFractal(gw, pt, r / 3, theta, order - 1);
		pt = drawFractal(gw, pt, r / 3, theta + 60 * invert, order - 1);
		pt = drawFractal(gw, pt, r / 3, theta - 60 * invert, order - 1);
		return drawFractal(gw, pt, r / 3, theta, order - 1);
	}
}
