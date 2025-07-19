/*
 * File: ex07.cpp
 * ----------------------
 *  Chapter 11 - ex07
 *  Rewrite the implementation of the merge sort
 *  algorithm form figure10-3 so that it sorts 
 *  an array rather than a vector.
 */
#include <iostream>
#include <iomanip>
#include "random.h"
using namespace std;

/* Constants */
const int N_ELEMENTS = 10;
const int MIN = 0;
const int MAX = 100;
const double COLOUMN_WIDTH = 4;

/* Function prototypes */
void generateRandomArray(int array[], int size);
void printArray(int array[], int size);
void sort(int array[], int size);
void merge(int array[], int num, int arr1[], int n1, int arr2[], int n2);


int main() {
    int array[N_ELEMENTS];
    generateRandomArray(array, N_ELEMENTS);
    cout << "Array before mergesort: " << endl;
    printArray(array, N_ELEMENTS);
    sort(array, N_ELEMENTS);
    cout << "Array after mergesort: " << endl;
    printArray(array, N_ELEMENTS);
    return 0;
}

void generateRandomArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = randomInteger(MIN, MAX);
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << left << setw(COLOUMN_WIDTH) << array[i];
    }
    cout << endl;
}

void sort(int array[], int size) {
    int leftArr[size / 2];
    int rightArr[size - size / 2];
    if (size <= 1) return;
    int *lh = &leftArr[0];
    int *rh = &rightArr[0];
    for (int i = 0; i < size; i++) {
        if (i < size / 2) {
            *lh++ = array[i];
        } else {
            *rh++ = array[i];
        }
    }
    sort(leftArr, size / 2);
    sort(rightArr, size - size / 2);
    merge(array, size, leftArr, size / 2, rightArr, size - size / 2);
    return;
}
        
void merge(int array[], int num, int arr1[], int n1, int arr2[], int n2) {
    int p1 = 0;
    int p2 = 0;
    int i = 0;
    while (p1 < n1 && p2 < n2) {
        if (arr1[p1] < arr2[p2]) {
            array[i] = arr1[p1++];
        } else {
            array[i] = arr2[p2++];
        }
        i++;
    }
    while (p1 < n1) array[i++] = arr1[p1++];
    while (p2 < n2) array[i++] = arr2[p2++];
}

