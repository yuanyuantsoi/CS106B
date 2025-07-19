/*
 * File: ex07.cpp
 * -----------------------------------
 *  Chapter10 - ex07
 *  The file experiment with different values of  the
 *  crossover point.
 */
#include <iostream>
#include <ctime>
#include <iomanip>
#include "vector.h"
#include "random.h"
using namespace std;

/* Constants */
const double COLUMN_ONE_WIDTH = 8;
const double COLUMN_TWO_WIDTH = 13;
const int NUM_CYCLES = 1000;
const int MIN = 0;
const int MAX = 10000;

Vector<int> getDataSizeVector();
void printTable();
void printTable(int n, double ssTime, double qsTime);
double getSSTime(Vector<int> & vec);
double getQSTime(Vector<int> & vec);
Vector<int> generateRandomVector(int n, int min, int max);
void sort(Vector<int> & vec);
void quicksort(Vector<int> & vec);
void recQuicksort(Vector<int> & vec, int start, int finish);
int partition(Vector<int> & vec, int start, int finish);

int main() {
    Vector<int> datasize = getDataSizeVector();
    // Table heading
    printTable();
    for (int i = 0; i < datasize.size(); i++) {
        int n = datasize[i];
        Vector<int> vec = generateRandomVector(n, MIN, MAX);
        double ssTime = getSSTime(vec) * 1000;
        double qsTime = getQSTime(vec) * 1000;
        printTable(n, ssTime, qsTime);
    }
    return 0;
}

void printTable() {
    cout << "     N     |    selection sort   |    quick sort    " << endl
         << "-----------+---------------------+------------------" << endl;
}

void printTable(int n, double ssTime, double qsTime) {
    cout << setw(8) << right << n << setw(4) << "|"
         << setw(15) << fixed << ssTime << setw(7) << "|"
         << setw(10) << qsTime << setw(8)  << endl;
}


Vector<int> getDataSizeVector(){
    Vector<int> vecN;
    //int times = 2;
    for (int n = 1; n <= 30; n++) {
        vecN.add(n);
    }
    return vecN;
}

double getSSTime(Vector<int> & vec) {
    int numTrials = 100;
    double elapsed = 0;
    for(int i = 0; i < numTrials; i++) {
        Vector<int> mutableData = vec;
        double start = double(clock()) / CLOCKS_PER_SEC;
        sort(mutableData);
        double finish = double(clock()) / CLOCKS_PER_SEC;
        elapsed = elapsed + (finish - start) ;
    }
    elapsed = elapsed / numTrials;
    return elapsed;
}

double getQSTime(Vector<int> & vec) {
    int numTrials = 100;
    double elapsed = 0;
    for(int i = 0; i < numTrials; i++) {
        Vector<int> mutableData = vec;
        double start = double(clock()) / CLOCKS_PER_SEC;
        quicksort(mutableData);
        double finish = double(clock()) / CLOCKS_PER_SEC;
        elapsed = elapsed + (finish - start) ;
    }
    elapsed = elapsed / numTrials;
    return elapsed;
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

void quicksort(Vector<int> & vec) {
    recQuicksort(vec, 0, vec.size() - 1);
}

void recQuicksort(Vector<int> & vec, int start, int finish){
    if (start >= finish) return;
    int boundary = partition(vec, start, finish);
    recQuicksort(vec, start, boundary - 1);
    recQuicksort(vec, boundary + 1, finish);
}

int partition(Vector<int> & vec, int start, int finish) {
    int pivot = vec[start];
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
    if (pivot <= vec[rh]) return start;
    vec[start] = vec[rh];
    vec[rh] = pivot;
    return rh;
}

