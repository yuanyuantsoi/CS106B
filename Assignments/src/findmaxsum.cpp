/*
 * File: findmaxsum.cpp
 * -----------------------
 *  Find the maximum sum of any its subvectors.
 */
#include <iostream>
#include <algorithm>
#include "random.h"
#include "vector.h"
using namespace std;

int recFindMaxSum(Vector<int> vec, int l, int u);

int main() {
    Vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.add(randomInteger(-10, 10));
    }
    cout << vec.toString() << endl;

    int currentSum = vec[0];
    int maxSum = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        currentSum = max((currentSum + vec[i]), vec[i]);
        maxSum = max(currentSum, maxSum);
    }
    cout << "maxSum = " << maxSum << endl;

    int maxSoFar = 0;
    int maxEndingHere = 0;
    for (int i = 0; i < vec.size(); i++) {
        maxEndingHere = max(maxEndingHere + vec[i], 0);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    cout << "MaxSoFar = " << maxSoFar << endl;

    int lower = 0;
    int upper = 0;
    return 0;
}

int recFindMaxSum(Vector<int> vec, int l, int u) {
    if (l > u) return 0;
    if (l == u) return vec[l];
    int m = (l + u) / 2;
    int leftSum = recFindMaxSum(vec, l, m);
    int rightSum = recFindMaxSum(vec, m, u);
    
