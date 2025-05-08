#include "gwindow.h"
#include "gobjects.h"
using namespace std;

/* Constants */

const double DEVITATION = 45;

void drawFractalTree(GWindow & gw, GPoint pt, double size);
void drawBranches(GWindow & gw, GPoint pt, double r, double theta, int order);

int main() {
	GWindow gw(1500,800);
	GPoint start(gw.getWidth() / 2, gw.getHeight());
	drawFractalTree(gw, start, gw.getHeight() / 2);
	return 0;
}

void drawFractalTree(GWindow & gw, GPoint pt, double size) {
	pt = gw.drawPolarLine(pt, size, 90);
	drawBranches(gw, pt, size / 2, 90, 8);
}

void drawBranches(GWindow & gw, GPoint pt, double r, double theta, int order) {
	if (order == 0) return;
	double lTheta = theta - DEVITATION;
	double rTheta = theta + DEVITATION;
	GPoint lPt = gw.drawPolarLine(pt, r, lTheta);
	drawBranches(gw, lPt, r / 2, lTheta, order - 1);
	GPoint rPt = gw.drawPolarLine(pt, r, rTheta);
	drawBranches(gw, rPt, r / 2, rTheta, order - 1);
}
	
	

