/*
 * File: ex18.cpp
 * ----------------
 *  This program simulates the chain reactions in the following experiment:
 *  	setup: cubical box, the bottom of which covered with 625 mousetraps,
 *  	formed by 25 mousetraps on a side. Each of mousetraps is loaded with 
 *  	two ping-pong balls.
 *  	1. one additional ball is relased from the top of the box and falls 
 *  	on one of the mousetraps.
 *  	2. the mouseetraps springs and shoots its two ping-pong balls into 
 *  	the air
 *  	3. the ping-pong ball bounce around side of the box and land on the floor.
 *
 *
 *  Simplifying assumption:
 *  	1. each ping-pong ball that falls always lands on a mousetrap
 *  	2. once a ball falls on a mousetrap, the ball stops and takes no further role
 *  	3. ball launched from the mousetrap bounce and land again after a random num
 *  	   of simulation cycles(1 - 4 sim cycles).
 */

#include <iostream>
#include <iomanip>
#include "vector.h"
#include "grid.h"
#include "random.h"
using namespace std;

/* Constants */
const int MIN_BALL_IN_AIR = 1;
const int MAX_BALL_IN_AIR = 4;
const int MOUSETRAP_SIDE_LENGTH = 25;
const int NUM_MOUSETRAP = MOUSETRAP_SIDE_LENGTH * MOUSETRAP_SIDE_LENGTH;

void printReports(Vector<int> nBallsByTime, int nSprungTraps);

int main() {
	Vector<int> ballCountsVector;
	Grid<bool> mousetrap(MOUSETRAP_SIDE_LENGTH, MOUSETRAP_SIDE_LENGTH);
	Vector<int> nBallsByTime;
	int nSprungTraps = 0;
	
	// relase the additional ball from the top
	ballCountsVector.add(0);
	while (!ballCountsVector.isEmpty()) {
		nBallsByTime.add(ballCountsVector.size());
		int nBall = ballCountsVector.size(); // the num of balls at the start of this time unit
		for (int i = nBall - 1; i >= 0; i--) {   // 方便添加和删除ball
			if (ballCountsVector[i] == 0) { // ball lands on mousetrap
				ballCountsVector.remove(i);
				int row = randomInteger(0, MOUSETRAP_SIDE_LENGTH - 1);
				int col = randomInteger(0, MOUSETRAP_SIDE_LENGTH -1);
				if (!mousetrap[row][col]) { //mousetrap == false, this trap hasn't sprung
					mousetrap[row][col] = true;
					nSprungTraps++;
					ballCountsVector.add(randomInteger(MIN_BALL_IN_AIR, MAX_BALL_IN_AIR));
					ballCountsVector.add(randomInteger(MIN_BALL_IN_AIR, MAX_BALL_IN_AIR));
				}
			} else {
				ballCountsVector[i]--;
			}
		}
	}

	printReports(nBallsByTime, nSprungTraps);

	return 0;
}


void printReports(Vector<int> nBallsByTime, int nSprungTraps) {
	cout << nBallsByTime.size() << " times units have elapsed since the begining." << endl;
	cout << (nSprungTraps * 1.0 / NUM_MOUSETRAP) * 100 << "% of the traps have been sprung." << endl;
	for (int i = 0; i < nBallsByTime.size(); i++) {
		cout << "At " << i << " time units, there are " << nBallsByTime[i] << " balls in the air." << endl;
	}
	cout << endl;
}
