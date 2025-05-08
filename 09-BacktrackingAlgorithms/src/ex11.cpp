#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool wildcardMatch(string filename, string pattern);

int main() {
    cout << wildcardMatch("US.txt", "*.*") << endl;
    cout << wildcardMatch("test", "*.*") << endl;
    cout << wildcardMatch("test.h", "test.?") << endl;
    cout << wildcardMatch("test.cpp", "test.?") << endl;
    cout << wildcardMatch("x", "??*") << endl;
    cout << wildcardMatch("yy", "??*") << endl;
    cout << wildcardMatch("zzz", "??*") << endl;
    return 0;
}

bool wildcardMatch(string filename, string pattern) {
    if (pattern.empty())  return filename.empty();

    if (pattern[0] == '?') {
        if (isalpha(filename[0]))  filename.erase(0, 1);
            else return false;
    } else if (pattern[0] == '*') {
        while (isalpha(filename[0])) {
            filename.erase(0, 1);
        }
    } else if (pattern[0] == filename[0]) {
        filename.erase(0,1);
    } else return false;
    return wildcardMatch(filename, pattern.substr(1));
}

