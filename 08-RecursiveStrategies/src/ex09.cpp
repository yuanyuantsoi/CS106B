/*
 * File: ex09.cpp
 * ---------------------------------------
 *  The program implements the Permutations program.
 */

#include <iostream>
#include <string>
#include "simpio.h"
using namespace std;

/* Function prototypes */

void listPermutations(string str);
void generatePermutations(string & str, int index);
void swapCharacter(string & str, int i, int j);

/* Main program */

int main() {
	string str = getLine("Enter string: ");
	listPermutations(str);
	return 0;
}

/*
 * Function: listPermutations
 * Usage: listPermutations(str);
 * -----------------------------------------------------
 * A warpper function of generatePermutations function.
 */

void listPermutations(string str) {
	generatePermutations(str, 0);
}

/*
 * Function: generatePermutations
 * Usage: generatePermutation(str, index);
 * -----------------------------------------------------
 *  The Function implements the permutations.
 */

void generatePermutations(string & str, int index) {
	if (index == str.length() - 1) {
		cout << str << endl;
	} else {
		for (int i = index; i < str.length(); i++) {
			swapCharacter(str, i, index);
			generatePermutations(str, index + 1);
			swapCharacter(str, i, index);
		}
	}
	return;
}

/*
 * Function: swapCharacter
 * Usage: swapCharacter(str, i, j);
 * -----------------------------------------------------
 *  The program swapCharacter of the string str between i
 *  and j.
 */
void swapCharacter(string & str, int i, int j) {
	char ch = str[i];
	str[i] = str[j];
	str[j] = ch;
}

