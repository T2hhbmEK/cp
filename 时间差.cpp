#include <bits/stdc++.h>
using namespace std;

int a[20];
int n = 1e6, m = 12;

bool check(int x) {
    for (int i = 1; i <= m; ++i) {
        if (x % i != a[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; ++i) {
        if (check(i)) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "gg" << "\n";
    return 0;
}
