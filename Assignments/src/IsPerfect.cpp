/*
 * File: IsPerfect.cpp
 * ----------------------
 *  CS106B - Assignment1.1
 *  IsPerfect - Writes a predict function IsPerfect that takes an integer n and returns true if n is perfect, and false otherwise.
 *  Main Program - The main program uses the IsPerfect function to check for perfect numbers in the range 1 to 10000, the perfect number will be printed on the screen.
 *  Perfect numbers - numbers that are equal to the sum of their proper divisiors.
 */

#include <iostream>
using namespace std;

bool IsPerfect(int n);

int main() {
	cout << "This program prints out the perfect numbers ranging from 1 to 10000" << endl;
	for (int i = 1; i <= 10000; i++) {
		if (IsPerfect(i)) cout << i << endl;
	}
	return 0;
}

/*
 * Function: bool IsPerfect(int);
 * Usage: if(IsPerfect(n))
 * -----------------------------
 *  This program takes an integer n and returns true if n is a perfect number, false otherwise.
 */
bool IsPerfect(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if ((n % i) == 0) sum += i;
	}
	return sum == n;
}	
	


