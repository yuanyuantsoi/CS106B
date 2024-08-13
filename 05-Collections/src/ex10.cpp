/*
 * File: ex10.cpp
 * ----------------------------------------------
 *  This program implements the function that initialize
 *  mineCounts accrocding to mingLocations.
 */

#include <iomanip>
#include "grid.h"
#include "simpio.h"
#include <iostream>
#include "vector.h"

void fixCounts(Grid<bool> & mines, Grid<int> & counts);
void printGrid(Grid<bool> & grid);
void printGrid(Grid<int> & grid);
void fillGrid(Grid<bool> & grid, Vector<bool> & vec);
int countGridsAround(Grid<bool>  mines, int row, int col);
int countOneGrid(Grid<bool> mines, int row, int col);

int main() {

	Grid<bool> mineLocations;
	mineLocations.resize(6, 6);
	
	Vector<bool> vec(36);
	vec[0] = vec[5] = vec[11] = true;
	vec[12] = vec[13] = vec[15] = vec[17] = true;
	vec[18] = true;
	vec[26] = true;
	fillGrid(mineLocations, vec);
	printGrid(mineLocations);

	Grid<int> mineCounts;
	fixCounts(mineLocations, mineCounts);
	
	cout << endl;
	printGrid(mineCounts);
	cout << endl;

	return 0;
}

void fillGrid(Grid<bool> & grid, Vector<bool> & vec) {
	for (int i = 0; i < grid.numRows(); i++) {
		for (int j = 0; j < grid.numCols(); j++) {
			grid[i][j] = vec[6 * i + j];
		}
	}
	return;
}

void printGrid(Grid<int> & grid) {
	for (int i = 0; i < grid.numRows(); i++) {
		for (int j = 0; j < grid.numCols(); j++) {
			cout << setw(4) << grid[i][j];
		}
		cout << endl;
	}
	return;
}

void printGrid(Grid<bool> & grid) {
	for (int i = 0; i < grid.numRows(); i++) {
		for (int j = 0; j < grid.numCols(); j++) {
			cout << setw(4) << (grid[i][j] ? "T" : "F");
		}
		cout << endl;
	}
	return;
}

void fixCounts(Grid<bool> & mines, Grid<int> & counts) {
	counts.resize(mines.numRows(), mines.numCols());
	for (int i = 0; i < counts.numRows(); i++) {
		for (int j = 0; j < counts.numCols(); j++) {
			counts[i][j] = countGridsAround(mines, i, j);
		}
	}
	return;
}

int countGridsAround(Grid<bool>  mines, int row, int col) {
	int total = 0;
	total += countOneGrid(mines, row - 1, col - 1)
		+countOneGrid(mines, row - 1, col)
		+countOneGrid(mines, row - 1, col + 1)
		+countOneGrid(mines, row, col - 1)
		+countOneGrid(mines, row, col)
		+countOneGrid(mines, row, col + 1)
		+countOneGrid(mines, row + 1, col - 1)
		+countOneGrid(mines, row + 1, col)
		+countOneGrid(mines, row + 1, col + 1);
	return total;
}

int countOneGrid(Grid<bool>  mines, int row, int col) {
	if (row < 0 || row >= mines.numRows()) return 0;
	if (col < 0 || col >= mines.numCols()) return 0;
	return (mines[row][col] ? 1 : 0);
}
