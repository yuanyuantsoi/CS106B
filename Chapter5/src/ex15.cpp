/*
 * File: ex15.cpp
 * -------------------------------------
 *  This program implements the roll(n, k) 
 *  operation on the specified stack.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "stack.h"
#include "vector.h"
#include "queue.h"
#include "simpio.h"
#include "error.h"
using namespace std;

void roll(Stack<char> & stack, int n, int k);
void printStack(Stack<char>  stack);

/* Main program */
int main() {
	Stack<char> stack;
	stack.push('A');
	stack.push('B');
	stack.push('C');
	stack.push('D');
	
	printStack(stack);
	
	
	roll(stack, 4, 1);
	cout << "Stack after roll(4, 1) : " << endl;
	printStack(stack);

	roll(stack, 3, 2);
	cout << "stack after roll(3, 2) : " << endl;
	printStack(stack);

	roll(stack, 2, 4);
	cout << "stack after roll(2, 4) : " << endl;
	printStack(stack);

	return 0;
}

/*
 * Function: printStack
 * Usage: printStack(stack);
 * ------------------------------------------
 *  This program prints the stack;
 */
void printStack(Stack<char> stack) {
	while (!stack.isEmpty()) {
		cout <<	stack.pop() << endl;
	}
	cout << endl;
}


/*
 * Function: roll
 * Usage: roll(stack, n, k);
 * ---------------------------------------
 *  The function rotate the top n elements 
 *  of a stack by k positions, where the 
 *  general direction is toward the top
 *  of the stack.
 *  Bounds: n and k should be nonnegative and n is not
 *  larger than the stack size, once violated, 
 *  the function will call error with ifno.
 */
void roll(Stack<char> & stack, int n, int k) {
	if (n < 0 || k < 0 || n > stack.size()) error("roll: argument out of range.");
	Queue<char> nQueue;
	for (int i = 0; i < n; i++) {
	       nQueue.enqueue(stack.pop());
	}

	for (int i = 0; i < k; i++) {
		char ch = nQueue.dequeue();
		nQueue.enqueue(ch);
	}

	Stack<char> rvsStack;
	while (!nQueue.isEmpty()) {
		rvsStack.push(nQueue.dequeue());
	}

	while (!rvsStack.isEmpty()) {
		stack.push(rvsStack.pop());
	}
	return;
}

	


