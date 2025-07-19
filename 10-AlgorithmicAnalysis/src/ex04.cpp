/*
 * File: ex04.cpp
 * -----------------------------------
 *  Chapter10 - ex04
 *  This file keeps track of the elapsed time as it executes the sort
 *  procedure on a randomly chosen vector.
 */
#include <iostream>
#include <ctime>
#include <iomanip>
#include <array>
#include "vector.h"
#include "random.h"
using namespace std;

/* Constants */
const double COLUMN_ONE_WIDTH = 8;
const double COLUMN_TWO_WIDTH = 13;
const int NUM_CYCLES = 1000;
const int MIN = 0;
const int MAX = 9999;
const int NUMBER = 1000;

Vector<int> generateNumberVector();
void printTable();
void printTable(int n, double time);
double getElapsedTime(Vector<int> & vec);
int getNumTrials(int n);
Vector<int> generateRandomVector(int n, int min, int max);
void sort(Vector<int> & vec);
Vector<int> sortInRange(Vector<int> & vec);

int main() {
    Vector<int> nums = generateNumberVector();
    //printTable();
    for (int i = 0; i < nums.size(); i++) {
        Vector<int> vec = generateRandomVector(nums[i], 0, 9999);
        double time = getElapsedTime(vec);
        //printTable(nums[i], time);
    }
    Vector<int> vec = generateRandomVector(20, 0, 9999);
    cout << vec.toString() << endl;
    vec = sortInRange(vec);
    cout << vec.toString() << endl;
    return 0;
}

void printTable() {
    cout << "  " 
         << setw(COLUMN_ONE_WIDTH / 2) << right << "N"
         << setw(COLUMN_ONE_WIDTH / 2) << " " << "|"
         << "  "
         << setw(COLUMN_TWO_WIDTH) << right << "Time (msec)" << endl;
    cout << setw(COLUMN_ONE_WIDTH + 2) << setfill('-') << "-" 
         << "+"
         << setw(COLUMN_TWO_WIDTH + 4) << setfill('-')  << "-" 
         << setfill(' ') << endl;
}

void printTable(int n, double time) {
        cout << setw(COLUMN_ONE_WIDTH) << right << n << "  |"
            << setw(COLUMN_TWO_WIDTH) << fixed << time << endl;
}


Vector<int> generateNumberVector(){
    Vector<int> vecN;
    int times = 2;
    //for (int n = 10; n <= 100000; n = n * times) {
    for (int n = 10; n <= 10; n = n * times) {
        vecN.add(n);
        times = (times == 5) ? 2 : 5;
    }
    return vecN;
}

double getElapsedTime(Vector<int> & vec) {
    int numTrials = getNumTrials(vec.size());
    double start = double(clock()) / CLOCKS_PER_SEC;
        for (int i = 0; i < numTrials; i++) {
            sortInRange(vec);
        }
    double finish = double(clock()) / CLOCKS_PER_SEC;
    double elapsed = (finish - start) / numTrials;
    return elapsed;
}

int getNumTrials(int n) {
    return ((n >= 1000) ? 1 : 1000);
}

Vector<int> generateRandomVector(int n, int min, int max) {
    Vector<int> vec;
    for (int i = 0; i < n; i++) {
        vec.add(randomInteger(min, max));
    }
    return vec;
}

void sort(Vector<int> & vec) {
    int n = vec.size();
    for (int lh = 0; lh < n; lh++) {
        int rh = lh;
        for (int i = lh + 1; i < n; i++) {
            if (vec[i] < vec[rh]) rh = i;
        }
        int tmp = vec[lh];
        vec[lh] = vec[rh];
        vec[rh] = tmp;
    }
}

Vector<int> sortInRange(Vector<int> & vec) {
    Vector<int> freq(10000, 0);
    Vector<int> result;
    for (int i = 0; i < vec.size(); i++) {
        int n = vec[i];
        freq[n] += 1;
    }
    for (int i = 0; i < freq.size(); i++) {
        for(int j = freq[i]; j > 0; j--) {
            result.add(i);
        }
    }
    return result;
}
