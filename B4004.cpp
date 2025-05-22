#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];
int n, m = 0;

bool chk() {
    for (int i = 1; i <= n; i++) {
        if (m % a[i] != 0) {
            return false;
        }
    }
    return true;
}

void solve() { // my main
    cin >> n;
    m = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        m = max(m, a[i]);
    }
    if (chk()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() { // O(t*n)
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    // t = 0
    return 0;
}
