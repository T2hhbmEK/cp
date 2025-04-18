#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        int b = pow(a, 1.0 / 4);
        if (a == b * b * b * b) {
            cout << b << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
