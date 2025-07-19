/*
 * File: ex14.cpp
 * -------------------------
 *  Chapter 10 - ex14
 */

#include <iostream>
#include "random.h"
#include "vector.h"
using namespace std;

int findDuplicate(Vector<int> vec);

int main() {
    Vector<int> vec;
    vec += 1, 2, 4, 5 ,3, 6, 7, 8, 9, 3;
    cout << vec.toString() << endl;
    cout << "Duplicate = " << findDuplicate(vec) << endl;
    return 0;
}

// 需要改变vector中的数字
/*
int findDuplicate(Vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        int index = vec[i];
        int tmp = 0;
        if (vec[index] == 0) return index;
        else if {
            tmp = vec[index];
            vec[i] = tmp;
            vec[index] = 0;
        }
    }
}
*/

int findDuplicate(Vector<int> vec) {
    int duplicate = -1;
    for (int i = 0; i < vec.size(); i++) {
        int index = abs(vec[i]);
        if (vec[index] < 0) {
            duplicate = index;
            break;
        } else {
            vec[index] *= -1;
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        vec[i] = abs(vec[i]);
    }
    return duplicate;
}
