/*
 * File: ex01.cpp
 * --------------------
 *  Thie file generates the bit patterns for
 *  the binary representation of all integers
 *  that can be represented using the specified
 *  number of bits.
 */
#include <iostream>
using namespace std;

void generateBinaryCode(int nBits);
void generateBinaryCodeRec(string prefix, int nBits);

int main() {
    generateBinaryCode(3);
    return 0;
}

void generateBinaryCode(int nBits) {
    generateBinaryCodeRec("", nBits);
}

void generateBinaryCodeRec(string prefix,int nBits) {
    if (nBits == 0) {
        cout << prefix << endl;
        return;
    }
    generateBinaryCodeRec(prefix + "0", nBits - 1);
    generateBinaryCodeRec(prefix + "1", nBits - 1);
}
