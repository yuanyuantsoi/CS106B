/*
 * File: ex04.cpp
 * -----------------------
 *  Chapter11 - ex04
 */

#include <iostream>
#include <string>
#include <cctype>
#include "strlib.h"
#include "simpio.h"
#include "queue.h"
#include "tokenscanner.h"
#include "strlibx.h"
#include "set.h"
using namespace std;

string HexCalculator(string equation);
bool isOperator(char ch);
int DecimalCalculator(Queue<int> operands, char op);
Set<char> setFromString(string str);

/* constant */
const Set<char> OPERATOR_SET = setFromString("+_?*");

int main() {
    while (true) {
        string input = getLine("> ");
        input = trim(input);
        if (input.empty()) break;
        string result = HexCalculator(input);
        cout << result << endl;
    }
    return 0;
}

string HexCalculator(string equation) {
    TokenScanner scanner(equation);
    scanner.ignoreWhitespace();
    Queue<int> operands;
    char op;
    while (scanner.hasMoreTokens()) {
        string token = scanner.nextToken();
        if (isalnum(token[0])) {
            int num = stringToInteger(token, 16);
            operands.enqueue(num);
        } else if (isOperator(token[0])){
            op = token[0];
        } else {
            error ("error.");
        }

    }
    int decResult = DecimalCalculator(operands, op);
    string hexResult = integerToString(decResult, 16);
    return hexResult;
}

bool isOperator(char ch) {
    return OPERATOR_SET.contains(ch);
}

int DecimalCalculator(Queue<int> operands, char op) {
    int a = operands.dequeue();
    int b = operands.dequeue();
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: error("error"); return 0;
    }
}

Set<char> setFromString(string str) {
    Set<char> set;
    for (int i = 0; i < str.size(); i++) {
        set.add(str[i]);
    }
    return set;
}
