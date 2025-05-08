#include <iostream>
#include "gevents.h"
#include "set.h"
#include "direction.h"
#include "maze.h"
#include "gwindow.h"
#include "point.h"
using namespace std;

/* constant */

const int NO_PATH = -1;

/* Function prototype */

Point adjacentPoint(Point start, Direction dir);
int shortestPathLength(Maze & maze, Point start);
bool recFindPath(Maze & maze, Point start, int & length, Set<int> & lengthSet);

int main() {
	GWindow gw;
	//Maze maze("Maze01.txt", gw);
	Maze maze("Maze03.txt", gw);
	Point start(0, 0);
	cout << "The shorteset length = " << shortestPathLength(maze, start) << endl;
	return 0;
}

int shortestPathLength(Maze & maze, Point start) {
	Set<int> lengthSet;
	int length = 0;
	recFindPath(maze, start, length, lengthSet);
	return lengthSet.isEmpty() ? NO_PATH : lengthSet.first();
}

bool recFindPath(Maze & maze, Point start, int & length, Set<int> & lengthSet) {
	if (maze.isOutside(start)) return true;
	if (maze.isMarked(start)) return false;
	maze.markSquare(start);
	length++;
	for (Direction dir = NORTH; dir <= WEST; dir++) {
		if (!maze.wallExists(start, dir)) {
			if (recFindPath(maze, adjacentPoint(start, dir), length, lengthSet)) {
				lengthSet.add(length);
				break;
			}
		}
	}
	maze.unmarkSquare(start);
	length--;
	return false;
}

Point adjacentPoint(Point start, Direction dir) {
	switch (dir) {
		case NORTH: return Point(start.getX(), start.getY() - 1);
		case EAST:  return Point(start.getX() + 1, start.getY());
		case SOUTH: return Point(start.getX(), start.getY() + 1);
		case WEST:  return Point(start.getX(), start.getY());
	}
	return start;
}
		
