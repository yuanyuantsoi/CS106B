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
struct moveTowers{
	int n; // number of disks to move
	char start; // name of spire used for start
	char finish; // name of spire used for finish
	char tmp; // name of spire used for temporary repositories
};

/* Function prototypes */
moveTowers generateNewTask(int n, char start, char finish, char tmp);
void moveSingleDisk(char start, char finish);


/* Main program */

int main() {
	Stack<moveTowers> pendingTasks;
	int n = getInteger("Enter n = ");
	pendingTasks.push(generateNewTask(n, 'A', 'B', 'C'));
	while (!pendingTasks.isEmpty()) {
		moveTowers currentTask = pendingTasks.pop();
		if (currentTask.n == 1) {
		       	moveSingleDisk(currentTask.start, currentTask.finish);
		} else {	
			pendingTasks.push(generateNewTask(currentTask.n - 1, currentTask.tmp, currentTask.finish, currentTask.start));
			pendingTasks.push(generateNewTask(1, currentTask.start, currentTask.finish, currentTask.tmp));
			pendingTasks.push(generateNewTask(currentTask.n - 1, currentTask.start, currentTask.tmp, currentTask.finish));
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

moveTowers generateNewTask(int n, char start, char finish, char tmp) {
	moveTowers newTask;
	newTask.n = n;
	newTask.start = start;
	newTask.finish = finish;
	newTask.tmp = tmp;
	return newTask;
}

/*
 * Function: moveSingleDisk
 * Usage: moveSingleDisk(start, finish);
 * -------------------------------------------------------------------
 * Prints the msg of moving one disk from spire in the name of start to the
 * spire in the name of finish.
 */
void moveSingleDisk(char start, char finish) {
	cout << start << " -> " << finish << endl;
}
