/*
 * File: ex11.cpp
 * ---------------------------------
 *  This program implements the function isSentencePalindrome(str)
 *  that returns true if the string str fits this definition of a 
 *  sentence palindrome.
 */

#include <string>
#include <cctype>
#include "simpio.h"
#include <iostream>
#include "strlib.h"
using namespace std;

bool isSentencePalindrome(string str);
string trimString(string str);
string reverseStr(string str);

int main() {
	cout << "This program tests for sentence palindromes." << endl;
	cout << "Indicate the end of the input with a blank line." << endl;
	while (true) {
		string str = getLine("Enter a sentence: ");
		if (str.empty()) break;
		if (isSentencePalindrome(str)) {
			cout << "That sentence is a palindrome." << endl;
		} else {
			cout << "That sentence is not a palindrome." << endl;
		}
	}
	return 0;
}


bool isSentencePalindrome(string str) {
	string strOnlyLetter = trimString(str);
	string rvsStr = reverseStr(strOnlyLetter);
	return equalsIgnoreCase(strOnlyLetter, rvsStr);
}	


string trimString(string str) {
	string result;
	for (int i = 0; i < str.length(); i++) {
		if (isalpha(str[i])) result += str[i];
	}
	return result;
}

string reverseStr(string str) {
	string result;
	for (int i = str.length() - 1; i >= 0; i--) {
		result += str[i];
	}
	return result;
}
