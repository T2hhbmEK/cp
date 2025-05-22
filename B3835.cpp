#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int y) {
    if (y % 100 == 0) {
        if (y % 400 == 0) {
            return true;
        } else {
            return false;
        }
    } else {
        if (y % 4 == 0) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (b == 2) {
        if (isLeapYear(a)) {
            cout << 29;
        } else {
            cout << 28;
        }
    } else {
        cout << month[b];
    }
    return 0;
}
