/*
 * File: ex15.cpp
 * ---------------------------------------
 *  This program rewrites the wordToPigLatin function so that
 *  any word begins with a capital letter in Enlish line still begins with
 *  a captital letter in pig latin.
 */

#include <string>
#include <cctype>
#include <iostream>
using namespace std;

/* Function prototypes */
string lineToPigLatin(string line);
string wordToPigLatin(string word);
int findFirstVowel(string word);
bool isVowel(char ch);

int main() {
	cout << "This program translates English to Pig Latin." << endl;
	string line;
	cout << "Enter English text: " ;
	getline(cin, line);
	string translation = lineToPigLatin(line);
	cout << "Pig latin outut: " << translation << endl;
	return 0;
}

string lineToPigLatin(string line) {
	string pigLine;
	int head = -1;
	for (int i = 0; i < line.length(); i++) {
		char ch = line[i];
		if (isalpha(ch)) {
			if (head == -1)	head = i;
		} else {
			if (head >= 0) {
				pigLine += wordToPigLatin(line.substr(head, i - head));	
				head = -1;
			}
			pigLine += ch;
		}
	}
	if (head >= 0) pigLine += wordToPigLatin(line.substr(head));
	return pigLine;
}

string wordToPigLatin(string word) {
	int vowelIndex = findFirstVowel(word);
	if (vowelIndex == -1) {
		return word;
	} else if (vowelIndex == 0) {
		return word + "way";
	} else {
		string head = word.substr(0, vowelIndex);
		string tail = word.substr(vowelIndex);
		if (isupper(word[0])) {
			head[0] = tolower(head[0]);
			tail[0] = toupper(tail[0]);
		}
		return tail + head + "ay";
	}
}

int findFirstVowel(string word) {
	for (int i = 0; i < word.length(); i++) {
		if (isVowel(word[i])) return i;
	}
	return -1;
}

bool isVowel(char ch) {
	string vowel = "aeiou";
	return (vowel.find(tolower(ch)) != string::npos);
}
