/*
 * File: ex08.cpp
 * ---------------------------------
 *  The program rewrite the Permutations program
 *  in a new strategy.
 */

#include <iostream>
#include <string>
#include "set.h"
#include "simpio.h"
using namespace std;

/* Function prototypes */

Set<string> generatePermutations(string str);

/* Main program */

int main() {
	string str = getLine("Enter a string: ");
	cout << "The permutations of \"" << str << "\" are: " << endl;
	Set<string> stringSet = generatePermutations(str);
	cout << stringSet.size() << " elements in the set" << endl;
	for (string s : stringSet) {
		cout << "  \"" << s << "\"" << endl;
	}
	
	return 0;
}

/*
 * Function: generatePermutations
 * Usage: Set<string> set = generatePermutations(str);
 * -------------------------------------------------------
 *  Returns a set of consisting of all permutations of the specified string.
 */

Set<string> generatePermutations(string str) {
	Set<string> result;
	if (str == "") {
		result += "";
	} else {
		char ch = str[0];
		string subStr = str.substr(1);
		for (string s : generatePermutations(subStr)) {
			for (int i = 0; i < s.length(); i++) {
			 	string newStr = s;
				result += newStr.insert(i, string(1, ch));
			}
			result += s + ch;
		}
	}
	return result;
}
