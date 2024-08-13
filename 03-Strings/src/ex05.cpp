/*
 * File: ex05.cpp
 * ----------------------------
 * This program reads in words and prints
 * their score in Scrabble. It ignore any 
 * characters other than uppercase.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
using namespace std;

/* Constants */
const string POINT_1_CHAR = "AEILNORSTU";
const string POINT_2_CHAR = "DG";
const string POINT_3_CHAR = "BCMP";
const string POINT_4_CHAR = "FHVWY";
const string POINT_5_CHAR = "K";
const string POINT_8_CHAR = "JX";
const string POINT_10_CHAR = "QZ";

int Scrabble(string word);
int charForScore(char ch);

int main() {
	string word = getLine("Enter word: ");
	cout << "The score of the word is " << Scrabble(word) << endl;
	return 0;
}

int Scrabble(string word) {
	int score = 0;
	for (int i = 0; i < word.length(); i++) {
		char ch = word[i];
		score += charForScore(ch);
	}
	return score;
}

int charForScore(char ch) {
	if (POINT_1_CHAR.find(ch) != string::npos) return 1;
	if (POINT_2_CHAR.find(ch) != string::npos) return 2;
	if (POINT_3_CHAR.find(ch) != string::npos) return 3;
	if (POINT_4_CHAR.find(ch) != string::npos) return 4;
	if (POINT_5_CHAR.find(ch) != string::npos) return 5; 
	if (POINT_8_CHAR.find(ch) != string::npos) return 8;
	if (POINT_10_CHAR.find(ch) != string::npos) return 10;
	return 0;
}
