/*
 * File: ex08.cpp
 * ------------------------------
 *  Chapter11 - ex08
 */
#include <iostream>
#include <fstream>
#include "tokenscanner.h"
using namespace std;

void setInput(istream & infile);

int main() {
    TokenScanner scanner;
    ifstream infile("test.txt");
    setInput(infile);
    return 0;
}

void setInput(istream & infile) {
    TokenScanner scanner;
    string text = "";
    string line;
    while (getline(infile, line)) {
        text += line;
    }
    scanner.setInput(text);
    while (scanner.hasMoreTokens()) {
        string token = scanner.nextToken();
        cout << token << endl;
    }
}
