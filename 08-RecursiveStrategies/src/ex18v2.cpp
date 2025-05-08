#include "gwindow.h"
#include "gobjects.h"
using namespace std;

void drawTri(GWindow & gw);
void recDrawTri(GWindow & gw, GPoint a, GPoint b, GPoint c, int order);

int main() {
	GWindow gw(1500, 800);
	drawTri(gw);
	return 0;
}

void drawTri(GWindow & gw) {
	double w = gw.getWidth();
	double h = gw.getHeight();
	double l = w * 0.55;
	GPoint a(w / 2 - l / 2, h / 10 *9);
	GPoint b(w / 2 + l / 2, h / 10 * 9);
	GPoint c(w / 2, h / 10 * 9 - l / 1.4);
	recDrawTri(gw, a, b, c, 5);
}


void recDrawTri(GWindow & gw, GPoint a, GPoint b, GPoint c, int order) {
	if (order == -1) return;
	gw.drawLine(a, b);
	gw.drawLine(a, c);
	gw.drawLine(b, c);
	GPoint midAB((a.getX() + b.getX()) / 2, (a.getY() + b.getY()) / 2);
	GPoint midAC((a.getX() + c.getX()) / 2, (a.getY() + c.getY()) / 2);
	GPoint midBC((b.getX() + c.getX()) / 2, (b.getY() + c.getY()) / 2);
	recDrawTri(gw, a, midAB, midAC, order - 1);
	recDrawTri(gw, b, midBC, midAB, order - 1);
	recDrawTri(gw, c, midBC, midAC, order - 1);
}
