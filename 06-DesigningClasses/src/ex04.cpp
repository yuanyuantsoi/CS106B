/*
 * File: ex04.cpp
 * -----------------
 *  The file draws the yarn pattern in the graphics window following these steps:
 *  	1. Place N_ACROSS pegs evenly along the top and bottom edges, N_DOWN pegs 
 *  	 along the left and right edge.
 *  	2. drawing lines between the pegs, starting aaat peg 0, and then moving 
 *  	 ahead a fixed number of spaces on each cycle, as specified by the constant 
 *  	 DELTA. For ex: DELTA = 11, the first line goes from peg 0 to peg 11, the second 
 *  	 goes from peg 11 to peg 22, and the third goes from peg 22 to peg 5.
 *  	3. The process continus in this way unitl the line returns to peg 0.
 */

#include <cstdlib>
#include <iostream>
#include "simpio.h"
#include "gwindow.h"
#include "gobjects.h"
#include "gtypes.h"
#include "vector.h"
using namespace std;

class YarnPatternFigure {

public:

	void getPegsSetup() {
		// get the parameters
		cout << "This program draws the Yarn pattern" << endl;
		N_ACROSS = getInteger("Enter the num of pegs along the top and bottom edge respectively: ");
		N_DOWN = getInteger("Enter the num of pegs along the left and right edges respectively: ");
		DELTA = getInteger("Enter the num of spaces on each cycle: ");
	}
	void drawLines() {
		gwWidth = gw.getWidth();
		gwHeight = gw.getHeight();
		//caclulate the space between adjacent pegs
		double widthGap = gw.getWidth() / (N_ACROSS - 1); // gap between adjacent pegs along the top and bottom edges
		double heightGap = gw.getHeight() / (N_DOWN - 1); // gap between adjacent pegs along the left and right edges

		// Set coordinates to each pegs
		int nPegs = (N_ACROSS + N_DOWN) * 2 - 4;
		Vector<GPoint> pegs;
		for (int i = 0; i < nPegs; i++) {
			double x, y;
			if (i < N_ACROSS) {  //set up top pegs 
				x = i * widthGap;
				y = 0;
			} else if (i < (N_ACROSS + N_DOWN - 1)) {
				x = gw.getWidth();
				y = (i - N_ACROSS) * heightGap;
			} else if (i < (2 * N_ACROSS + N_DOWN -2)) {
				x = (nPegs - N_DOWN + 1 - i) * widthGap;
				y = gw.getHeight();
			} else {
				x = 0;
				y = (nPegs - i) * heightGap;
			}
			GPoint pt(x, y);
			pegs.add(pt);
		}


		// Draw lines between pegs
		int start = 0;
		int end = DELTA;
		while (end != 0) {
			GPoint startPt = pegs[start];
		        GPoint endPt = pegs[end];
			gw.setColor("BLUE");
			gw.drawLine(startPt, endPt);
			
			start = end;
			end = (end + DELTA) % nPegs;
		}
	}

	void drawPattern() {
		getPegsSetup();
		drawLines();
	}


private: 
	int N_ACROSS;
	int N_DOWN;
	int DELTA;
	GWindow gw;
	double gwWidth;
	double gwHeight;
};

int main() {
	YarnPatternFigure pattern;
	pattern.drawPattern();
	return 0;
}
