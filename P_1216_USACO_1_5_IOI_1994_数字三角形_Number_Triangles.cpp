#include <bits/stdc++.h>
using namespace std;
const int N = 1E3 + 5;
int r, a[N][N], dp[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = r; i >= 1; --i) {
        dp[i] = a[r][i];
    }
    for (int i = r - 1; i >= 1; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[j] = max(dp[j], dp[j + 1]) + a[i][j];
        }
    }
    cout << dp[1];
    return 0;
}