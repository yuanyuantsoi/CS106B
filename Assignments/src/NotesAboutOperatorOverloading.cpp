/*
 * Class Operator overloading
 * -----------------------------
 */
// Point operator< overloading
bool operator<(Point a, Point b) {
    if (a.getX() != b.getX()) {
        return (a.getX() < b.getX());
    } else {
        return (a.getY() < b.getY());
    }
}

/*
 * Struct operator overloading
 * -------------------------------
 */
struct logT{
    string str;
};

ostream & operator<<(ostream & os, logT log) {
    return os << log.str;
}
