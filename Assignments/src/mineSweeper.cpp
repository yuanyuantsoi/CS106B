/*
 * File: mineSweeper.cpp
 * ---------------------
 *  This program implements the function same as Chapter5-ex10,
 *  which will constructs a new grid of integers storing the count
 *  of bombs in each neighborhood.
 */

#include <iostream>
#include "grid.h"
#include "simpio.h"
using namespace std;

bool locationOnGrid(int row, int col, Grid<int> & bombCounts);
void UpdateCounts(int row, int col, Grid<int> & bombCounts);

Grid<int> MakeGridOfCounts(Grid<bool> & bombLocations);

int main() {
	Grid<bool> bombLocations(3, 3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			bombLocations[i][j] = false;
		}
	}

	bombLocations[0][1] = true;
	
	Grid<int> bombCounts = MakeGridOfCounts(bombLocations);
	for (int i = 0; i < 3; i++) {
		for (int j  = 0; j < 3; j++) {
			cout << " " << bombCounts[i][j] << " " ;
		}
		cout << endl;
	}
	return 0;
}

bool locationOnGrid(int row, int col, Grid<int> & bombCounts) {
	return row >= 0 && col >= 0 && row < bombCounts.numRows() 
		&& col < bombCounts.numCols();
}


void UpdateCounts(int row, int col, Grid<int> & bombCounts) {
	for (int i = (row - 1); i <= (row + 1); i++) {
		for (int j = (col - 1); j <= (col + 1); j++) {
			if (locationOnGrid(i, j, bombCounts)) {
					bombCounts[i][j]++;
			}
		}
	}
}


Grid<int>  MakeGridOfCounts(Grid<bool> & bombLocations) {
	Grid<int> bombCounts(bombLocations.numRows(), bombLocations.numCols());
	for (int i = 0; i < bombCounts.numRows(); i++) {
		for (int j = 0; j < bombCounts.numCols(); j++) {
			bombCounts[i][j] = 0;
		}
	}

	for (int i = 0; i < bombCounts.numRows(); i++) {
		for (int j = 0; j < bombCounts.numCols(); j++) {
			if (bombLocations[i][j]) {
				UpdateCounts(i, j, bombCounts);
			}
		}
	}
	return bombCounts;
}
