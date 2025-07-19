/*
 * File: ex13.cpp
 * -------------------------
 *  Chapter 10 - ex13
 */

#include <iostream>
#include "vector.h"
#include "random.h"
using namespace std;

int findMajorityElement(Vector<int> & vec);

int main() {
    Vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.add(randomInteger(1, 2));
    }
    vec.clear();
    vec += 1, 2, 3, 4, 5, 5;
    cout << vec.toString() << endl;
    cout << "MajorityElement = " << findMajorityElement(vec) << endl;
    return 0;
}

int findMajorityElement(Vector<int> & vec) {
    int count = 0;
    int num = -1;
    for (int i = 0; i < vec.size(); i++) {
        if (count == 0) {
            num = vec[i];
            count++;
        } else if (num == vec[i]) count++;
        else count--;
    }
    if (count > 0) return num;
    else return -1;
}
