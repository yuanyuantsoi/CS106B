/*
 * File: ex23.cpp
 * ---------------
 *  This program generates a three-letter word list that can be formed by
 *  adding a letter to the front or back of a two -letter word.
 *  ?????? These two-letter word are meaningful word or just random comb? -- word included in the EnglishWords.dat
 *  List structure:
 *  	set - for each word to be one and only.
 */

#include <iostream>
#include <iomanip>
#include "lexicon.h"
#include "set.h"
#include <string>
#include <cctype>
using namespace std;

void getTwoLetterWord(Lexicon dict, Set<string> & wordSet);

int main() {
	Lexicon english("EnglishWords.dat");
	Set<string> twoLetterWord;
	Set<string> threeLetterWord;
	getTwoLetterWord(english, twoLetterWord);

	for (string word : twoLetterWord) {
		for (char ch = 'a'; ch <= 'z'; ch++) {
			if (english.contains(ch + word)) {
				threeLetterWord.add(word); 
			} else if (english.contains(word + ch)) {
				threeLetterWord.add(word);
			}
		}
	}
	return 0;
}

void getTwoLetterWord(Lexicon dict, Set<string> & wordSet) {
 	string word = "xx";
	for (char c0 = 'a'; c0 <= 'z';  c0++) {
		word[0] = c0;
		for (char c1 = 'a';  c1 <= 'z'; c1++) {
			word[1] = c1;
			if (dict.contains(word)) wordSet.add(word);
		}
	}
}
