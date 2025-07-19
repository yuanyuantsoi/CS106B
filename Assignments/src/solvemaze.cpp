/*
 * File: solvemaze.cpp
 * -------------------------------------
 *  Section Handout #5 - Problem 4: Search Algorithms
 *  This file solve the non-perfect maze using 
 *  breadth-first search and depth-first search respectivly.
 */
#include <iostream>
#include <time.h>
#include "direction.h"
#include "point.h"
#include "gwindow.h"
#include "maze.h"
#include "vector.h"
#include "set.h"
#include "stack.h"
#include "queue.h"
#include "direction.h"
#include "error.h"
using namespace std;

struct PathT{
    Stack<Point> stackP;
    Set<Point> setP;
};

// Point operator< overloading
bool operator<(Point a, Point b) {
    if (a.getX() != b.getX()) {
        return (a.getX() < b.getX());
    } else {
        return (a.getY() < b.getY());
    }
}

bool solveMazeBreadthFirst(Maze & maze, PathT & bfsPath);
bool addPtToPath(PathT & path, Point & pt);
void printPath(PathT & path);
Point adjacentPoint(Point & pt, Direction dir);
void markPath(Maze & maze, PathT & path);
bool solveMazeDepthFirst(Maze & maze);
bool recSolveMazeDFS(Maze & maze, Point pt);
bool solveMazeRightHandRule(Maze & maze);
bool recSolveMazeRHR(Maze & maze, Point pt);
Direction getDirectionToMove(Maze & maze, Point pt);

int main() {
    // Breadth-First search 
    GWindow gw;
    gw.setWindowTitle("BFS - Solution");
    
    Maze maze("SampleMaze.txt", gw);
    PathT bfsPath;
    clock_t start, end;
    start = clock();
    bool sol = solveMazeBreadthFirst(maze, bfsPath);
    end = clock();
    cout << "BFS-time = " << double(end-start)/CLOCKS_PER_SEC<<"S"<< endl;
    //if (solveMazeBreadthFirst(maze, bfsPath)) {
    if (sol) {
        markPath(maze, bfsPath);
    } else {
        cout << "Solution path not found using BFS." << endl;
    }

    // Depth-First search
    GWindow gw2;
    gw2.setWindowTitle("DFS - Solution");

    Maze maze2("SampleMaze.txt", gw2);
    clock_t start1, end1;
    start1 = clock();
    bool sol1 = solveMazeDepthFirst(maze2);
    end1 = clock();
    cout << "DFS-time = " << double(end1-start1)/CLOCKS_PER_SEC<<"S"<< endl;
    if (sol1) {
        cout << "Found the solution using DFS." << endl;
    } else {
        cout << "Solution path not found using BFS." << endl;
    }
    // Right Hand rule
    GWindow gw3;
    gw3.setWindowTitle("Right-Hand Rule");
    Maze maze3("SampleMaze.txt", gw3);
    if (solveMazeRightHandRule(maze3)) {
        cout << "Found the solution using right hand rule." << endl;
    } else {
        cout << "Solution path not found using right hand rule." << endl;
    }
    return 0;
}

bool solveMazeBreadthFirst(Maze & maze, PathT & bfsPath) {
    PathT path;
    Point start = maze.getStartPosition();
    addPtToPath(path, start);
    Queue<PathT> pathsQueue;
    pathsQueue.enqueue(path);
    while (true) {
        if (pathsQueue.isEmpty()) break;
        PathT minPath = pathsQueue.dequeue();
        Point endpoint = minPath.stackP.peek();
        for (Direction dir = NORTH; dir <= WEST; dir++) {
            if (!maze.wallExists(endpoint, dir)) {
                Point nbrPt = adjacentPoint(endpoint, dir);
                if (maze.isOutside(nbrPt)) {
                    bfsPath = minPath;
                    return true;
                }
                if (!minPath.setP.contains(nbrPt)) {
                    PathT newPath = minPath;
                    addPtToPath(newPath, nbrPt);
                    pathsQueue.enqueue(newPath);
                }
            }
        }
    }
    return false;
}

bool addPtToPath(PathT & path, Point & pt) {
    if (path.setP.contains(pt)) return false;
    path.stackP.push(pt);
    path.setP.add(pt);
    return true;
}

void printPath(PathT & path) {
    cout << "Stack: " << endl;
    cout << path.stackP.toString() << endl;
    
    cout << "Set: " << endl;
    for (Point pt : path.setP) {
        cout << pt.toString() << endl;
    }
}

Point adjacentPoint(Point & pt, Direction dir) {
    int x = pt.getX();
    int y = pt.getY();
    switch (dir) {
        case NORTH: 
            y--;
            break;
        case WEST:
            x--;
            break;
        case SOUTH:
            y++;
            break;
        case EAST:
            x++;
            break;
        default:
            return pt;
    }
    Point nbrPt(x,y);
    return nbrPt;
}

void markPath(Maze & maze, PathT & path) {
    while (!path.stackP.isEmpty()) {
        Point pt = path.stackP.pop();
        maze.markSquare(pt);
    }
}

bool solveMazeDepthFirst(Maze & maze) {
   return recSolveMazeDFS(maze, maze.getStartPosition());
}

bool recSolveMazeDFS(Maze & maze, Point pt) {
    // Simple cases: 
    if (maze.isOutside(pt)) return true;   // Check pt in bounds first, then check if it is marked. - Essential 
    if (maze.isMarked(pt)) return false;
    // Recursively case:
    maze.markSquare(pt);
    for (Direction dir = NORTH; dir <= WEST; dir++) {
        if (!maze.wallExists(pt, dir)) {
            Point nextPt = adjacentPoint(pt, dir);
            if (recSolveMazeDFS(maze, nextPt))  return true;
        }
    }
    maze.unmarkSquare(pt);
    return false;
}

bool solveMazeRightHandRule(Maze & maze) {
    return recSolveMazeRHR(maze, maze.getStartPosition());
}

bool recSolveMazeRHR(Maze & maze, Point pt) {
    // Simple case:
    if (maze.isOutside(pt)) return true;
    if (maze.isMarked(pt)) return false;

    // Recursive case:
    maze.markSquare(pt);
    Direction dir = getDirectionToMove(maze, pt);
    Point nextPt = adjacentPoint(pt, dir);
    if (recSolveMazeRHR(maze, nextPt)) {
        return true;
    } else {
        maze.unmarkSquare(pt);
        return false;
    }
}

Direction getDirectionToMove(Maze & maze, Point pt) {
    for (Direction dir = NORTH; dir <= WEST; dir++) {
        if (!maze.wallExists(pt, dir) && maze.wallExists(pt, (Direction)((dir + 1) % 4))) {
            return dir;
        }
    }
    error("No place to move");
}
