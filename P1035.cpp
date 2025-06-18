#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n = 0;
    cin >> k;
    double s = 0;
    while (s <= k) {
        s += 1.0 / ++n;
    }
    cout << n << endl;
    return 0;
}
