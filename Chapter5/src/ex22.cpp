/*
 * File: ex22.cpp
 * ----------------
 *  This program uses the function isPalindrome defined in section 3.6
 *  to display all the words in the English lexicon that are palindromes.
 */

#include "lexicon.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

string reverse(string str);
bool isPalindrome(string str);

int main() {
	Lexicon english("EnglishWords.dat");
	for (string word : english) {
		if (isPalindrome(word)) 
			cout << word << endl;
	}
	return 0;
}

bool isPalindrome(string str) {
	return str == reverse(str);
}

string reverse(string str) {
	string result = "";
	for (int i = str.length() - 1; i >= 0; i--) {
		result += str[i];
	}
	return result;
}
