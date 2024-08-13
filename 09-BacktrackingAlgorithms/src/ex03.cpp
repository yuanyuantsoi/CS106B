/*
 * File: ex03.cpp
 * ----------------------------------
 *  The program findPath to the maze.
 */

#include <iostream>
#include <string>
#include "direction.h"
#include "point.h"
#include "maze.h"
#include "vector.h"
using namespace std;

bool findSolutionPath(Maze & maze, Point start, Vector<Point> & path);
void printSolutionPath(Maze & maze, Vector<Point> & path);
Point adjacentPoint(Point start, Direction dir);
void removePointFromPath(Vector<Point> & path, Point pt);
bool pointInPath(Vector<Point> & path, Point pt);

int main() {
	GWindow gw;
	Maze maze("SampleMaze.txt", gw);
	Vector<Point> solutionPath;
	findSolutionPath(maze, maze.getStartPosition(), solutionPath);
	
	GWindow gw2;
	Maze maze2("SampleMaze.txt", gw2);
	printSolutionPath(maze2, solutionPath);

	return 0;
}

/*
 * Function: findSolutionPath
 * Usage: if( findSolutionPath(maze, start, path));
 * ------------------------------------------------------------------
 *  The function uses the recursive strategy to find the solution path
 *  to the maze.
 *
 */

bool findSolutionPath(Maze & maze, Point start, Vector<Point> & path) {
	// Simple cases
	if (maze.isOutside(start)) return true;
	if (pointInPath(path, start))  return false;

	// Resursive case
	path.add(start);
	for (Direction dir = NORTH; dir <= WEST; dir++) {
		if (!maze.wallExists(start, dir)) {
			if (findSolutionPath(maze, adjacentPoint(start, dir), path)) {
				return true;
			}
		}
	}
	removePointFromPath(path, start);
	return false;
}

/*
 * Function: printSolutionPath
 * Usage: void printSolutionPath(maze, solutionPath);
 * --------------------------------------------------------------------
 *  Print the solution path on a new window.
 */

void printSolutionPath(Maze & maze, Vector<Point> & path) {
	//if (path.isEmpty()) return;
	for (int i = 0; i < path.size(); i++) {
		maze.markSquare(path[i]);
	}
}




/*
 * Function: adjacentPoint
 * Usage: Point finish = adjacentPoint(start, dir);
 * ------------------------------------------------
 * Returns the point that results from moving one square from start
 * in the direction specified by dir.  For example, if pt is the
 * point (1, 1), calling adjacentPoint(pt, EAST) returns the
 * point (2, 1).  To maintain consistency with the graphics package,
 * the y coordinates increase as you move downward on the screen.  Thus,
 * moving NORTH decreases the y component, and moving SOUTH increases it.
 */

Point adjacentPoint(Point start, Direction dir) {
   switch (dir) {
    case NORTH: return Point(start.getX(), start.getY() - 1);
    case EAST:  return Point(start.getX() + 1, start.getY());
    case SOUTH: return Point(start.getX(), start.getY() + 1);
    case WEST:  return Point(start.getX() - 1, start.getY());
   }
   return start;
}


/*
 * Function: removePointFromPath
 * Usage: void removePointFromPath(path, pt);
 * -----------------------------------------------------------
 *  Removes the point from Vector<point> path.
 */

void removePointFromPath(Vector<Point> & path, Point pt) {
	for (int i = 0; i < path.size(); i++) {
		if (path[i] == pt) path.remove(i);
	}
}


/*
 * Function: pointInPath
 * Usage: if(pointInPath(path, pt))
 * -------------------------------------------------------
 *  Return true if the point if inside the vector.
 */

bool pointInPath(Vector<Point> & path, Point pt) {
	for (int i = 0; i < path.size(); i++) {
		if (path[i] == pt) return true;
	}
	return false;
}
