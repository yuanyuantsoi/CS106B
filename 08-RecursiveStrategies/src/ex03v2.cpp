/*
 * File: ex03.cpp
 * -------------------------------------------
 *  This program implements the towers of hanoi that 
 *  it uses an explicit stack of pending tasks instead of recursion.
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "stack.h"
using namespace std;

/* Struct */
struct moveTower{
	int n; // number of disks to move
	char start; // name of spire used for start
	char finish; // name of spire used for finish
	char tmp; // name of spire used for temporary repositories
};

/* Function prototypes */
void pushNewTask(Stack<moveTower> & list, int n, char start, char finish, char tmp);

/* Main program */

int main() {
	Stack<moveTower> moveList;
	int n = getInteger("Enter n = ");
	cout << "Move " << n << " disks from A to B, using C as a tmp." << endl;
	pushNewTask(moveList, n, 'A', 'B', 'C');
	while (!moveList.isEmpty()) {
		moveTower current = moveList.pop();
		if (current.n == 1) {
			cout << current.start << " -> " << current.finish << endl;
		} else {	
			pushNewTask(moveList, current.n - 1, current.tmp, current.finish, current.start);
			pushNewTask(moveList, 1, current.start, current.finish, current.tmp);
			pushNewTask(moveList, current.n - 1, current.start, current.tmp, current.finish);
		} 
	}
	return 0;
}


/*
 * Function: genrrateNewTask
 * Usage:struct moveTowers newTask = generateNewTask(n, start, finish, tmp);
 * -----------------------------------------------------------------------------
 *  Return a new sturcture of moveTowers defined by the arguments n, start, finish,
 *  tmp.
 */

void pushNewTask(Stack<moveTower> & list, int n, char start, char finish, char tmp) {
	moveTower newTask;
	newTask.n = n;
	newTask.start = start;
	newTask.finish = finish;
	newTask.tmp = tmp;
	list.push(newTask);
}
