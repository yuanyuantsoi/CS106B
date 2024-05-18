/*
 * File: ex16.cpp
 * -----------------------------------
 *  This program implement the function obengloblish.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
#include "strlib.h"
using namespace std;

string obenglobish(string word);
bool isVowel(char ch);

int main() {
	while (true) {
		string word = getLine("Enter a word: ");
		if (word == "") break;
		string trans = obenglobish(word);
		cout << word << " -> " << trans << endl;
	}
	return 0;
}

string obenglobish(string word) {
	string obWord = "";
	bool lastVowel = false;
	for (int i = 0; i < word.length(); i++) {
		if (!lastVowel && isVowel(word[i])) {
				if (!(i == (word.length() - 1) && word[i] == 'e')) obWord += "ob";
		}
		obWord += word[i];

		lastVowel = isVowel(word[i]) ? true : false;
	}
		return obWord;
}

bool isVowel(char ch) {
	string vowel ="aeiou";
	bool isV = (vowel.find(tolower(ch)) != string::npos);
	return isV;
}
