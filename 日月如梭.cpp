#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b && a > c) {
        cout << 0 << " ";
    } else {
        cout << max(b, c) + 1 - a << " ";
    }
    if (b > a && b > c) {
        cout << 0 << " ";
    } else {
        cout << max(a, c) + 1 - b << " ";
    }
    if (c > a && c > b) {
        cout << 0 << " ";
    } else {
        cout << max(a, b) + 1 - c << " ";
    }
    return 0;
}