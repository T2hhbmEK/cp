#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int N = 1e5 + 10;

int m;
int a[3][N], ans = INT_MAX;

int f(int k) {
    int t = -1;
    for (int j = 0; j < k; j++) {
        for (int i : {j % 2, (j % 2) ^ 1}) {
            t = max(a[i][j] + 1, t + 1);
        }
    }
    int i = k % 2;
    for (int j = k; j < m; j++) {
        t = max(a[i][j] + 1, t + 1);
    }
    i = i ^ 1;
    for (int j = m - 1; j >= k; j--) {
        t = max(a[i][j] + 1, t + 1);
    }
    return t;
}

signed main() {
    cin >> m;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    a[0][0] = -1;
    for (int k = 0; k < m; k++) {
        ans = min(ans, f(k));
    }
    cout << ans;
    return 0;
}
