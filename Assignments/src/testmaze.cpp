#include <iostream>
#include "set.h"
#include "point.h"
using namespace std;
int compareEntry(Point pt1, Point pt2);

int main() {
    Set<Point> set(compareEntry);
    return 0;
}

int compareEntry(Point pt1, Point pt2) {
    if ((pt1.getX() == pt2.getX()) && (pt2.getY() == pt2.getY()))
        return 0;
    if ((pt1.getX() < pt2.getX())) 
        return -1;
    return 1;
}
