/*
 * File: ex02.cpp
 * ---------------------------------
 *  Chapter10 - Algorithmic Analysis ex02
 *  This file implements the insertion sort.
 */
#include <iostream>
#include "vector.h"
#include "simpio.h"
#include "random.h"
using namespace std;

void insertionSort(Vector<int> & vec);

int main() {
    Vector<int> vec;
    for(int i = 0; i < 10; i++) {
        vec.add(randomInteger(0, 100));
    }
    cout << vec.toString() << endl;
    insertionSort(vec);
    cout << vec.toString() << endl;
    return 0;
}

void insertionSort(Vector<int> & vec) {
    for (int i = 1; i < vec.size(); i++) {
        int cur = vec[i];
        int j;
        for (j = i - 1; j >= 0 && vec[j] > cur; j--) {
            vec[j+1] = vec[j];
        }
        vec[j+1] = cur;
    }
}

