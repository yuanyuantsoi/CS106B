/*
 * File: ReverseQueue.cpp
 * -----------------------
 *  This program implements the function reverseQueue that 
 *  reverses the elemens in the passed in queue.
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "stack.h"
#include "queue.h"
using namespace std;

void reverseQueue(Queue<int> & q);

int main() {
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	
	reverseQueue(q);

	while (!q.isEmpty()) {
		cout << q.dequeue() << endl;
	}
	return 0;
}

void reverseQueue(Queue<int> & q) {
	Stack<int> rvs;
	while (!q.isEmpty()) {
		rvs.push(q.dequeue());
	}

	while (!rvs.isEmpty()) {
		q.enqueue(rvs.pop());
	}
}

