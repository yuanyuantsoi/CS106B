/*
 * Function: ex06.cpp
 * ----------------------
 *  Chapter 10 - ex06
 *  Change the implementation of the quick sort algorithm
 *  so that, instead of picking the first element in the vector
 *  as the pivot, the partition function chooses the
 *  median of the first, middle and last elements.
 */

#include <iostream>
#include "vector.h"
#include "random.h"
#include "error.h"
using namespace std;

Vector<int> generateVector(int n);
void quickSort(Vector<int> & vec);
void recQuickSort(Vector<int> & vec, int start, int finish);
int partition(Vector<int> & vec, int start, int finish);
int getMedianIndex(Vector<int> & vec, int start, int finish);

int main() {
    Vector<int> vec = generateVector(10);
    cout << vec.toString() << endl;
    quickSort(vec);
    cout << vec.toString() << endl;
    return 0;
}

Vector<int> generateVector(int n) {
    Vector<int> vec;
    for (int i = 0; i < n; i++) {
        vec.add(randomInteger(0,1000));
    }
    return vec;
}

void quickSort(Vector<int> & vec) {
    recQuickSort(vec, 0, vec.size() - 1);
}

void recQuickSort(Vector<int> & vec, int start, int finish){
    //cout << vec.toString() << endl;
    if (start >= finish) return;
    int boundary = partition(vec, start, finish);
    recQuickSort(vec, start, boundary - 1);
    recQuickSort(vec, boundary + 1, finish);
}

int partition(Vector<int> & vec, int start, int finish) {
    int medianIndex = getMedianIndex(vec, start, finish);
    int pivot = vec[medianIndex];
    vec[medianIndex] = vec[start];
    vec[start] = pivot;
    int lh = start + 1;
    int rh = finish;
    while (true) {
        while (lh < rh && vec[rh] >= pivot) rh--;
        while (lh < rh && vec[lh] < pivot) lh++;
        if (lh == rh) break;
        int tmp = vec[lh];
        vec[lh] = vec[rh];
        vec[rh] = tmp;
    }
    vec[start] = vec[rh];
    vec[rh] = pivot;
    return rh;
}

int getMedianIndex(Vector<int> & vec, int start, int finish) {
    int mid = (start + finish) / 2;
    int a = vec[start];
    int b = vec[mid];
    int c = vec[finish];
    if ((a >= b && b >= c) || (c >= b && b >= a)) {
        return mid;
    }
    if ((b >= c && c >= a) || (a >= c && c >= b)) {
        return finish;
    }
    if ((b >= a && a >= c) || (c >= a && a >= b))
        return start;
    error("getMedian error");
    return 0;
}
