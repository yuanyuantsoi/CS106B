/*
 * File: ex02.cpp
 * -------------------
 *  Generates the gray code patterns.
 *  3-bit Gray code   2-bit Gray code   1-bit Gray code
 *  000
 *  001
 *  011                00
 *  010                01                    0
 *  ---                --                    -
 *  110                11                    1
 *  111                10
 *  101
 *  100
 *
 *  参考github
 *
 */

#include <iostream>
#include <string>
#include "vector.h"
using namespace std;

void generateGrayCode(int nBits);
void generateGrayCodeRec(int nBits, Vector<string> & basecode);

int main() {
    cout << "3-bit Gray code: " << endl;
    generateGrayCode(3);
    cout << "2-bit Gray code: " << endl;
    generateGrayCode(2);
    cout << "1-bit Gray code: " << endl;
    generateGrayCode(1);
    return 0;
}

void generateGrayCode(int nBits) {
    Vector<string> basecodes;
    basecodes += "0", "1";
    generateGrayCodeRec(nBits, basecodes);
}

void generateGrayCodeRec(int nBits, Vector<string> & basecode) {
    if (nBits == 0) return;
    if (nBits == 1) {
        for (int i = 0; i < basecode.size(); i++) 
            cout << basecode[i] << endl;
    }

    Vector<string> newcode;

    for (int i = 0; i < basecode.size(); i++) {
        newcode.add("0" + basecode[i]);
    }

    for (int i = basecode.size() - 1; i >= 0; i--) {
        newcode.add("1" + basecode[i]);
    }
    generateGrayCodeRec(nBits - 1, newcode);
}
