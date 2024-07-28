/*
 * File: ex01.cpp
 * ------------------------
 *  This program implements the moveTower function and coutn HanoiMoves function.
 */

#include <iostream>
#include <string>
#include "simpio.h"
using namespace std;

/* Function prototypes */

void moveTower(int n, char start, char finish, char tmp);
void moveSingleDisk(char start, char finish);
int countHanoiMoves(int n);

/* Main program */

int main() {
	int n = getInteger("Enter n = ");
	moveTower(n, 'A', 'B', 'C');
	cout << "It takes " << countHanoiMoves(n) << " steps to move " << n << " disks." << endl;
	return 0;
}

/*
 * Function: countHanoiMoves
 * Usage: int n = countHanoiMoves(n);
 * -------------------------------------------
 *  Count the number of steps to move n Hanoi 
 *  disks.
 */
int countHanoiMoves(int n) {
	if (n == 0) return 0;
	return 1 + countHanoiMoves(n - 1) * 2;
}

/*
 * Function: moveTower
 * Usage: moveTower(n, start, finish, tmp);
 * ----------------------------------------------
 *  Moves a tower of size n from the start spire to the finish 
 *  spire using the tmp spire as the temporary repository.
 */
void moveTower(int n, char start, char finish, char tmp) {
	if (n == 0) {
		return;
	} else {
		moveTower(n - 1, start, tmp, finish);
		moveSingleDisk(start, finish);
		moveTower(n - 1, tmp, finish, start);
	}
}

/*
 * Function: moveSingleDisk
 * Usage: moveSingleDisk(start, finish);
 * -----------------------------------------------------------
 * Exexutes the transfer of a single disk from the start spire to
 * the finish spire.
 * In this implementation, the move is simply displayed on the console;
 * in a graphical implementation, the code would update the graphics window to 
 * show the new arrangement.
 */
void moveSingleDisk(char start, char finish) {
	cout << start << " -> " << finish << endl;
}



