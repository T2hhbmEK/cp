#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int N = 1e5 + 10;

int m;
int a[2][N], ans = INT_MAX;
int dpL[N], dpR[2][N];

signed main() {
    cin >> m;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    a[0][0] = -1;
    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < 2; i++) {
            dpR[i][j] = dpR[i][j + 1] + 1;
            dpR[i][j] = max(dpR[i][j], a[i ^ 1][j] + 2 * (m - j));
            dpR[i][j] = max(dpR[i][j], a[i][j] + 1);
        }
    }
    int t = -1;
    for (int j = 0; j < m; j++) {
        int i = j % 2;
        ans = min(ans, max(dpR[i ^ 1][j], t + 2 * (m - j)));
        t = max({a[i][j] + 2, a[i ^ 1][j] + 1, t + 2});
    }
    cout << ans;
    return 0;
}
