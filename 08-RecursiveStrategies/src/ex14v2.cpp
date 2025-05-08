#include "gobjects.h"
using namespace std;

const double HALF_INCH_TICK = 100;
const double MIN_TICK = HALF_INCH_TICK / 8;

void drawRuler(GWindow & gw);
void recDrawTick(GWindow & gw, double startX, double endX, double height, double tick);

int main() {
	GWindow gw;
	drawRuler(gw);
	return 0;
}


void drawRuler(GWindow & gw) {
	recDrawTick(gw, gw.getWidth() / 3, gw.getWidth() / 3 * 2, gw.getHeight() / 3 * 2, HALF_INCH_TICK);
	return;
}

void recDrawTick(GWindow & gw, double startX, double endX, double height, double tick) {
	if (tick < MIN_TICK) return;
	double mid = (startX + endX) / 2;
	gw.add(new GLine(mid, height, mid, (height - tick)));
	gw.add(new GLine(startX, height, endX, height));
	recDrawTick(gw, startX, mid, height, tick / 2);
	recDrawTick(gw, mid, endX, height, tick / 2);
}
