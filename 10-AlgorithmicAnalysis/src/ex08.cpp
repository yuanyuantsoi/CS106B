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
const int SELECTION_SORT = 1;
const int QUICK_SORT = 2;
const int HYBRID_SORT = 3;

/* Type definations */
struct SortLog{
    int n; // data size
    int th; // threshold
    double time;
};


ostream & operator<<(ostream & os, SortLog log) {
    return os << setw(8) << right << log.n
              << setw(15) << log.th 
              << setw(15) << fixed << log.time;
}

Vector<int> getDataSizeVector();
double getElapsedTime(Vector<int> & vec, int fnOption, int th);
Vector<int> generateRandomVector(int n, int min, int max);
void sort(Vector<int> & vec);
void quicksort(Vector<int> & vec);
void recQuicksort(Vector<int> & vec, int start, int finish);
int partition(Vector<int> & vec, int start, int finish);
void hybridsort(Vector<int> & vec, int threshold);
void partQuicksort(Vector<int> & vec, int start, int finish, int threshold);
void insertionsort(Vector<int> & vec);
void printLog(Vector<SortLog> & log);

int main() {
    Vector<int> datasize = getDataSizeVector();
    for (int i = 0; i < datasize.size(); i++) {
        int n = datasize[i];
        Vector<int> vec = generateRandomVector(n, MIN, MAX);
        Vector<SortLog> log;
        Vector<int> th;
        th += 2, 3, 4, 5, 8, 9, 10, 20, 50, 100;
        for (int i = 0; i < th.size(); i++) {
            double hybridTime = getElapsedTime(vec, HYBRID_SORT, th[i]) * 1000;
            SortLog cur;
            cur.n = vec.size();
            cur.th = th[i];
            cur.time = hybridTime;
            log.add(cur);
        }
        printLog(log);
    }
    return 0;
}

Vector<int> getDataSizeVector(){
    Vector<int> vecN;
    int times = 2;
    for (int n = 10; n <= 100000; n *= times) {
        vecN.add(n);
        times = (times == 2) ? 5 : 2;
    }
    return vecN;
}

double getElapsedTime(Vector<int> & vec, int fnOption, int th) {
    int numTrials = 100;
    double elapsed = 0;
    for(int i = 0; i < numTrials; i++) {
        Vector<int> mutableData = vec;
        double start = double(clock()) / CLOCKS_PER_SEC;
        if (fnOption == SELECTION_SORT) {
        //    sort(mutableData);
        } else if (fnOption == QUICK_SORT) {
          //  quicksort(mutableData);
        } else if (fnOption == HYBRID_SORT) {
            hybridsort(mutableData, th);
        }
        double finish = double(clock()) / CLOCKS_PER_SEC;
        elapsed += (finish - start) ;
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

void hybridsort(Vector<int> & vec, int threshold) {
    partQuicksort(vec, 0, vec.size() - 1, threshold);
    insertionsort(vec);
}

void partQuicksort(Vector<int> & vec, int start, int finish, int threshold) {
    int size = finish - start + 1;
    if (size <= threshold) return;
    int boundary = partition(vec, start, finish);
    partQuicksort(vec, start, boundary - 1, threshold);
    partQuicksort(vec, boundary + 1, finish, threshold);
}

void insertionsort(Vector<int> & vec) {
    for (int i = 1; i < vec.size(); i++) {
        int cur = vec[i];
        int j ;
        for (j = i - 1; j >= 0 && vec[j] > cur; j--) {
            vec[j+1] = vec[j];
        }
        vec[j + 1] = cur;
    }
}

void printLog(Vector<SortLog> & log) {
    cout << "    N    |    Threshold  |   Time   " << endl
         << "---------+---------------+-----------" << endl;
    for (int i = 0; i < log.size(); i++) {
        SortLog cur = log[i];
        cout << cur << endl;
    }
}
