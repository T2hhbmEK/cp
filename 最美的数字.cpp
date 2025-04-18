#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    if (n == 1) {
        if (t <= 9) {
            cout << t;
        } else {
            cout << -1;
        }
        return 0;
    }
    int x = 1;
    for (int i = 2; i <= n; i++) {
        x = 10 * x % t;
    }
    if (x != 0) {
        x = t - x;
    }
    cout << 1;
    for (int i = 2; i < n; i++) {
        cout << 0;
    }
    cout << x;
    return 0;
}
