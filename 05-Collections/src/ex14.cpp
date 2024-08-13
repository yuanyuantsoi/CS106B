/*
 * File: ex14.cpp
 * ---------------------------------------------------------------
 *  This program checks whether the bracketing operators in a string
 *  are properly mathed.
 *  The function using stack structures.
 */

#include <iostream>
#include <string>
#include "stack.h"
#include "simpio.h"
using namespace std;

bool isBracketsMatched(string str);

int main() {
	string str = getLine("Enter string: ");
	if (isBracketsMatched(str)) {
		cout << "Matched brackets." << endl;
	} else {
		cout << "Unmatched brackets." << endl;
	}
	return 0;
}

bool isBracketsMatched(string str) {
	Stack<char> matchBrackets;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '{') matchBrackets.push('{');
		if (str[i] =='(') matchBrackets.push('(');
		if (str[i] == '[') matchBrackets.push('[');
		if (str[i] == '}') {
			if (matchBrackets.isEmpty() || (matchBrackets.pop() != '{')) {
				return false;
			}
		}
		if (str[i] == ')') {
			if (matchBrackets.isEmpty() || (matchBrackets.pop() != '(')) {
				return false;
			}
		}
		if (str[i] == ']') {
			if (matchBrackets.isEmpty() || (matchBrackets.pop() != '[')) {
				return false;
			}
		}
	}
	return matchBrackets.isEmpty();
}
