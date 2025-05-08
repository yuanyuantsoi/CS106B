#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "strlib.h"
#include "set.h"
#include "lexicon.h"
using namespace std;

string digitToChar(char ch);
void listMnemonics(string str);
void recListMnemonics(Lexicon & english, string prefix, string rest);
void recPrefixToWords(Lexicon & english, string prefix);

int main() {
	listMnemonics("72547");
	return 0;
}

void listMnemonics(string str) {
	Lexicon english("EnglishWords.txt");
	recListMnemonics(english, "", str);
}
 
string digitToChar(char ch) {
	switch (ch) {
	case '2': return "ABC";
	case '3': return "DEF";
	case '4': return "GHI";
	case '5': return "JKL";
	case '6': return "MNO";
	case '7': return "PQRS";
	case '8': return "TUV";
	case '9': return "WXYZ";
	default: return "";
	}
}
void recListMnemonics(Lexicon & english, string prefix, string rest) {
	if (rest == "") {
		if (english.containsPrefix(prefix)) recPrefixToWords(english, prefix);
		return;
	}
	string letters = digitToChar(rest[0]);
	for (int i = 0; i < letters.size(); i++) {
		recListMnemonics(english, prefix + letters[i], rest.substr(1));
	}
}

void recPrefixToWords(Lexicon & english, string prefix) {
	if (!english.containsPrefix(prefix)) return;
	if (english.contains(prefix)) cout << toLowerCase(prefix) << endl;
	for (char ch = 'a'; ch <= 'z'; ch++) {
		recPrefixToWords(english, prefix + ch);
	}
}
