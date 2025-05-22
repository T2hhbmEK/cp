#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    cout << (x - 1 + n) % 7 + 1;
    // x = (x + n) % 7;
    // if (x == 0) x = 7;
    // cout << x;
    return 0;
}
