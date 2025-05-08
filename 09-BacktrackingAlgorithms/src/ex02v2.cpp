/*
 * File: ex02.cpp
 * -------------------
 * This program extends the solveMaze program so that it records the number of recursive
 * calls as it proceeds.
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

bool solveMaze(Maze & maze, Point pt, int & nCall);
bool solveMazeNoUnmark(Maze & maze, Point pt, int & nCall);
Point adjacentPoint(Point start, Direction dir);

/* Main program */

int main() {
   GWindow gw;
   Maze maze("SampleMaze2.txt", gw);
   int nCall = 0;
   if (solveMaze(maze, maze.getStartPosition(), nCall)) {
      cout << "The marked path is a solution." << endl;
   } else {
      cout << "No solution exists." << endl;
   }
   cout << "solveMaze has been called " << nCall << " times." << endl;
   
  GWindow gw2;
   Maze maze2("SampleMaze2.txt", gw2);
   int nCall2 = 0;
   if (solveMazeNoUnmark(maze2, maze2.getStartPosition(), nCall2)) {
      cout << "The marked path is a solution." << endl;
   } else {
      cout << "No solution exists." << endl;
   }
   cout << "solveMaze has been called " << nCall2 << " times." << endl;

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

bool solveMaze(Maze & maze, Point start, int & nCall) {
	nCall++;
   if (maze.isOutside(start)) return true;
   if (maze.isMarked(start)) return false;
   maze.markSquare(start);
   for (Direction dir = NORTH; dir <= WEST; dir++) {
      if (!maze.wallExists(start, dir)) {
         if (solveMaze(maze, adjacentPoint(start, dir), nCall)) {
            return true;
         }
      }
   }
   maze.unmarkSquare(start);
   return false;
}

bool solveMazeNoUnmark(Maze & maze, Point start, int & nCall) {
	nCall++;
   if (maze.isOutside(start)) return true;
   if (maze.isMarked(start)) return false;
   maze.markSquare(start);
   //bool possibility = true;
   for (Direction dir = NORTH; dir <= WEST; dir++) {
     // cout << "Direction = " << dir << endl;
	if (!maze.wallExists(start, dir)) {
	 if (solveMazeNoUnmark(maze, adjacentPoint(start, dir), nCall)) {
            return true;
	 }
      }
     // if (dir == WEST) possibility = false;
     // cout << "possibility = " << possibility << endl;
   }
   //if (possibility) maze.unmarkSquare(start);
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
