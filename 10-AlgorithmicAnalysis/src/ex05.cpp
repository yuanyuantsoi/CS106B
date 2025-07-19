/*
 * Function: ex05.cpp
 * -----------------------------------
 *  Chapter10 - ex05
 *  The program generates a table comparing the
 *  performance of two algorithms - linear and
 *  binary search - when used to find a randomly
 *  chosen integer key in a sorted Vector<int>.
 */
#include <iostream>
#include <string>
#include <iomanip>
#include "console.h"
#include "vector.h"
#include "random.h"
#include "error.h"
using namespace std;

/* Constants */
const double COLUMN_WIDTH = 14;

Vector<int> getNumList();
Vector<int> getSortedVector(int n);
Vector<int> generateRandomVector(int n, int min, int max);
void printTable();
void printTable(int n, double numLinear, double numBinary);
void quickSort(Vector<int> & vec);
void recQuickSort(Vector<int> & vec, int start, int end);
int partition(Vector<int> & vec, int start, int end);
int getNumTrials(int n);
int getRandomKey(Vector<int> & vec);
int linearSearch(Vector<int> & vec, int key, int & numComp);
int binarySearch(Vector<int> & vec, int key, int & numComp);

int main() {
    Vector<int> numsList = getNumList();
    printTable();
    for (int i = 0; i < numsList.size(); i++) {
        int n = numsList[i];
        Vector<int> vec = getSortedVector(n);
        int totalCompLinear = 0;
        int totalCompBinary = 0;
        int numTrials = getNumTrials(n);
        for (int j = 0; j < numTrials; j++) {
            int key = getRandomKey(vec);
            linearSearch(vec, key, totalCompLinear);
            binarySearch(vec, key, totalCompBinary);
        }
        double numLinear = double(totalCompLinear) / numTrials;
        double numBinary = double(totalCompBinary) / numTrials;
        printTable(n, numLinear, numBinary);
    }
    return 0;
}

Vector<int> generateRandomVector(int n, int min, int max) {
    Vector<int> vec;
    for (int i = 0; i < n; i++) {
        vec.add(randomInteger(min, max));
    }
    return vec;
}

Vector<int> getSortedVector(int n) {
    Vector<int> vec = generateRandomVector(n, 0, 9999);
    quickSort(vec);
    return vec;
}

void printTable() {
    cout << "     N    |   Linear   |   Binary   " << endl;
    cout << "----------+------------+------------" << endl;
}

void printTable(int n, double numLinear, double numBinary) {
    cout << setw(8) << right << n << "  |"
         << setw(10) << fixed << setprecision(1) << numLinear << "  |"
         << setw(10) << fixed << setprecision(1) << numBinary << endl;
}

void quickSort(Vector<int> & vec) {
    recQuickSort(vec, 0, vec.size() - 1);
}

void recQuickSort(Vector<int> & vec, int start, int end) {
    if (start >= end) return;
    int boundary = partition(vec, start, end);
    recQuickSort(vec, start, boundary - 1);
    recQuickSort(vec, boundary + 1, end);
}

int partition(Vector<int> & vec, int start, int end) {
    int pivot = vec[start];
    int lh = start + 1;
    int rh = end;
    while (true) {
        while (vec[rh] >= pivot && rh > lh) rh--;
        while (vec[lh] < pivot && rh > lh) lh++;
        if (lh == rh) break;
        int tmp = vec[lh];
        vec[lh] = vec[rh];
        vec[rh] = tmp;
    }
    if (pivot <= vec[rh]) return start;
    vec[start] = vec[rh];
    vec[rh] = pivot;
    return rh;
}
    
Vector<int> getNumList() {
    Vector<int> numList;
    int times = 2;
    for (int n = 10; n <= 100000; n = n * times) {
        numList.add(n);
        times = (times == 2) ? 5 : 2;
    }
    return numList;
}

int getNumTrials(int n) {
    if (n <= 5000) {
        return 100;
    } else {
        return 10;
    }
}

int getRandomKey(Vector<int> & vec) {
    int index = randomInteger(0, vec.size() - 1);
    if (randomChance(0.5)) {
        return vec[index];
    } else {
        return randomInteger(-99999, 999999);
    }
}

int linearSearch(Vector<int> & vec, int key, int & numComp) {
    for (int i = 0; i < vec.size(); i++) {
        numComp++;
        if (vec[i] == key) return i;
    }
    return -1;
}

int binarySearch(Vector<int> & vec, int key, int & numComp) {
    int lh = 0;
    int rh = vec.size() - 1;
    while (lh <= rh) {
        numComp++;
        int mid = (lh + rh) / 2;
        if (vec[mid] == key) return mid;
        if (vec[mid] > key) {
            rh = mid - 1;
        } else {
            lh = mid + 1;
        }
    }
    return -1;
}
