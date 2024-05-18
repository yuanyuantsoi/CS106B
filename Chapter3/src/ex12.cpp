/*
 * File: ex12.cpp
 * -------------------------------------------
 *  This program implements a function createRegularPlural(word) that
 *  returns the plural of word formed by following standard English rules;
 */

#include <string>
#include <cctype>
#include "simpio.h"
#include "strlib.h"
using namespace std;

string createRegularPlural(string word);
 
int main() {
	while (true) {
		string word = getLine("Enter a word: ");
		if (word.empty()) break;
		cout << "The plural is " << createRegularPlural(word) << endl;
	}
	return 0;
}


string createRegularPlural(string word) {
	if (endsWith(word, 's') || endsWith(word, 'x') || endsWith(word,'z') 
			|| endsWith(word,"ch") || endsWith(word,"sh")) 
		return word + "es";
	if (endsWith(word,'y')) {
			char ch = word[word.length() - 2];
			string vowel = "aeiou";
			if (vowel.find(tolower(ch)) == string::npos) 
				return word.replace(word.length() - 1, 1, "ies");
	}
	return word + "s";
}
