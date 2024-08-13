/*
 * File: SolveMaze.cpp
 * -------------------
 * This program solves a maze by recursive backtracking.
 * 参考Eric Roberts 和 zenglenn42(Github)代码。
 */

#include <iostream>
#include <string>
#include "direction.h"
#include "gwindow.h"
#include "maze.h"
#include "point.h"
#include "set.h"
#include "gevents.h"
using namespace std;

/* Constants */
const int NO_PATH = -1;

/* Function prototypes */

bool solveMaze(Maze & maze, Point pt);
Point adjacentPoint(Point start, Direction dir);
int shortestPathLength(Maze & maze, Point start);
bool findAllPath(Maze & maze, Point start, int & length, Set<int> & pathLength);

/* Main program */

int main() {
   GWindow gw;
   Maze maze("SampleMaze.txt", gw);
   if (solveMaze(maze, maze.getStartPosition())) {
      cout << "The marked path is a solution." << endl;
   } else {
      cout << "No solution exists." << endl;
   }
   

   return 0;
}

/*
 * Function: solveMaze
 * Usage: solveMaze(maze, start);
 * ------------------------------
 * Attempts to generate a solution to the current maze from the specified
 * start point.  The solveMaze function returns true if the maze has a
 * solution and false otherwise.  The implementation uses recursion
 * to solve the submazes that result from marking the current square
 * and moving one step along each open passage.
 */

bool solveMaze(Maze & maze, Point start) {
   if (maze.isOutside(start)) return true;
   if (maze.isMarked(start)) return false;
   maze.markSquare(start);
   for (Direction dir = NORTH; dir <= WEST; dir++) {
      if (!maze.wallExists(start, dir)) {
         if (solveMaze(maze, adjacentPoint(start, dir))) {
            return true;
         }
      }
   }
   maze.unmarkSquare(start);
   return false;
}

/*
 * Function: shortestPathLength
 * Usage: int length = shortestPathLength(Maze & maze, Point start);
 * ------------------------------------------------------------------------
 *  Returns the length of the shortest path in the maze form the specifies position 
 *  to any exit. If there is no solution, shortestPathLength should return -1.
 */

int shortestPathLength(Maze & maze, Point start) {
	Set<int> pathLength;
	int length = 0;
	findAllPath(maze, start, length, pathLength);
	if (pathLength.size() == 0) {
		return NO_PATH;
	} else {
		return pathLength.first();
	}
}

bool findAllPath(Maze & maze, Point start, int & length, Set<int> & pathLength) {
   if (maze.isOutside(start)) return true;
   if (maze.isMarked(start)) return false;
   maze.markSquare(start);
   length++;
   cout << "length = " << length << endl;
   waitForClick();

   for (Direction dir = NORTH; dir <= WEST; dir++) {
      if (!maze.wallExists(start, dir)) {
         if (findAllPath(maze, adjacentPoint(start, dir), length, pathLength)) {
           	pathLength.add(length);
		cout << "Add " << length << " to set." << endl;
		waitForClick();
		break;
         }
      }
   }
   maze.unmarkSquare(start);
   length--;
   cout << "length = " << length << endl;
   waitForClick();
   return false;
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
