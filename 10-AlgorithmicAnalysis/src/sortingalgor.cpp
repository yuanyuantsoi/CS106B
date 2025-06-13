/*
 * File: sortingalgor.cpp
 * 2025.06.10 Yuan
 * ---------------------------------------------
 *  This file implements the most used algorithm for sorting.
 *  1. selection sort
 *  2. merge sort
 *  3. quick sort
 */
#include <iostream>
#include "vector.h"
#include "random.h"
using namespace std;

static void getRandomVector(Vector<int> & vec);
static void selectionSort(Vector<int> & vec);
static bool swap(Vector<int> & vec, int i, int j);
static Vector<int> mergeSort(Vector<int> & vec);
static Vector<int> recMergeSort(Vector<int> & vec, int startIndex, int endIndex);
static Vector<int> merge(Vector<int> & vec1, Vector<int> & vec2);
static Vector<int> quickSort(Vector<int> & vec);
static Vector<int> easyMerge(Vector<int> & lHalf, Vector<int> & hHalf);

int main() {
	Vector<int> vec1, vec2, vec3;
	getRandomVector(vec1); // fill vector
	cout << "Origin vector: " << endl;
	cout << vec1.toString() << endl;

	// Selection sort
	selectionSort(vec1);
	cout << vec1.toString() << endl;

	getRandomVector(vec2);
	cout << "Origin vector: " << endl;
	cout << vec2.toString() << endl;

	// Merge sort
	Vector<int> sortedVec2 = mergeSort(vec2);
	cout << "Sorted Vector: " << endl;
	cout << sortedVec2.toString() << endl;

	cout << "Origin vector: " << endl;
	getRandomVector(vec3);
	cout << vec3.toString() << endl;

	// Quick sort
	Vector<int> sortedVec3 = quickSort(vec3);
	cout << "Sorted Vector(quick sort): " << endl;
	cout << sortedVec3.toString() << endl;
	return 0;
}

/*
 * Function: getRandomVector
 * Usage: getVector(vec);
 * ----------------------------------------
 *  Use random integer between 0 - 200 (inclusive) to fill
 *  vector.
 */
static void getRandomVector(Vector<int> & vec) {
	for (int i = 0; i < 10; i++) {
		vec.add(randomInteger(0, 200));
	}
}

/*
 * Function: selectionSort
 * Usage: selectionSort(vec);
 * ---------------------------------------------
 *  This implements the selection sort to sort out the vector.
 *  With your left hand point at each element in the vector in turn,
 *  starting at index 0. At each step in the cycle:
 *  
 * 1. Find the smallest element in the range between your left hand and the
 *    end of the vector, and point at that element with your right hand(rh).
 * 
 * 2. Move that element into its correct position by exchanging the elements
 *    indicated by your left and right hands.
 */ 
static void selectionSort(Vector<int> & vec) {
	cout << "Selection sort: " << endl;
	int n = vec.size();
	for (int lh = 0; lh < n; lh++) {
		int rh = lh;
		for (int i = lh + 1; i < n; i++) {
			if (vec[rh] > vec[i]) rh = i;
		}
		swap(vec, lh, rh);
		cout << vec.toString() << endl;
	}
}

/*
 * Function: swap
 * Usage: swap(vec, i, j);
 * ----------------------------------------------
 *  Exchange the elements at index i, and index j.
 *  Return false if i or j is out of bounds.
 *  Return ture if the swap is completed.
 */
static bool swap(Vector<int> & vec, int i, int j) {
	if ((i >= vec.size()) && (j >= vec.size())) return false;
	int tmp = vec[i];
	vec[i] = vec[j];
	vec[j] = tmp;
	return true;
}

/*
 * Function: mergeSort
 * Usage: mergeSort(vec);
 * -----------------------------------------------
 *  Sort the vector vec using merge sort algorithm.
 *  Call the recursive funciont recMergeSort to do the 
 *  resursive work.
 */
static Vector<int> mergeSort(Vector<int> & vec) {
	return recMergeSort(vec, 0, vec.size() - 1);
}

/*
 * Function: recMergeSort
 * Usage: Vector<int> vec = recMergeSort(vec, size);
 * -----------------------------------------------------
 *  Sorting the vec using merge sorting.
 *  1. divides the vec into half vectors
 *  2. merge sort each half of the vectors
 *  3. merge the two vectors into a new vector
 */
static Vector<int> recMergeSort(Vector<int> & vec, int startIndex, int endIndex) {
	// Simple case - vec has 1 element 
	if (startIndex == endIndex) {
		Vector<int> sorted;
		sorted.add(vec[startIndex]);
		return sorted;
	}

	// Recursive case : divide, sort, merge
	Vector<int> vec1 = recMergeSort(vec, startIndex, (startIndex + endIndex) / 2);
	Vector<int> vec2 = recMergeSort(vec, (startIndex + endIndex) / 2 + 1,  endIndex);
	return merge(vec1, vec2);
}

/*
 * Function: merge
 * Usage: merge(vec1, vec2);
 * -------------------------------------------------------
 *  Merge vec1 and vec2 in specified order into a new vector.
 *  Return the new vector.
 */
static Vector<int> merge(Vector<int> & vec1, Vector<int> & vec2){
	Vector<int> sorted;
	while ((!vec1.isEmpty()) && (!vec2.isEmpty())) {
		if (vec1[0] < vec2[0]) {
			sorted.add(vec1[0]);
			vec1.remove(0);
		}else {
			sorted.add(vec2[0]);
			vec2.remove(0);
		}
	}
	sorted += vec1;
	sorted += vec2;
	return sorted;
}


/*
 * Function: quickSort
 * Usage: Vector<int> sorted = quickSort(vec);
 * --------------------------------------------------------
 *  Implements the quick sort algorithm using "divide and conquer"
 *  algorithm.
 *  1. divide input into low half and high half
 *  2. recursively sort each half
 *  3. join two haves together
 */
static Vector<int> quickSort(Vector<int> & vec) {
	if (vec.size() == 1) return vec;
	int boundary = vec[0];
	Vector<int> lowHalf, highHalf;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] < boundary) {
			lowHalf.add(vec[i]);
		} else {
			highHalf.add(vec[i]);
		}
	}
	return easyMerge(lowHalf, highHalf);
}

/*
 * Function: easyMerge
 * Usage: Vector<int> vec = easyMerge(lHalf, hHalf);
 * --------------------------------------------------
 *  Merge the lower half and higher half by containcating
 *  two halve together.
 */
static Vector<int> easyMerge(Vector<int> & lHalf, Vector<int> & hHalf) {
	lHalf += hHalf;
	return lHalf;
}


