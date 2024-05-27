/*
 * File: ex13.cpp
 * ------------------------------------------------------
 *  This program implements the function revereQueue that
 *  reverses the elements in the queue.
 */

#include <iostream>
#include <iomanip>
#include "queue.h"
#include "vector.h"
#include "stack.h"
#include "simpio.h"
using namespace std;

void reverseQueue (Queue<string> & queue);

int main() {
	Queue<string> myQueue;
	
	cout << "Enter a list of strings, ending with empty string: " << endl;
	while (true) {
		string str = getLine("? ");
		if (str.empty()) break;
		myQueue.enqueue(str);
	}

	reverseQueue(myQueue);

	while (!myQueue.isEmpty()) {
		string str = myQueue.dequeue();
		cout << str << endl;
	}

	return 0;
}

void reverseQueue(Queue<string> & queue) {
	Stack<string> rvs;
	while (!queue.isEmpty()) {
		rvs.push(queue.dequeue());
	}

	while (!rvs.isEmpty()) {
		queue.enqueue(rvs.pop());
	}

	return;
}
