#include <bits/stdc++.h>
using namespace std;
const int N = 1E3 + 5;

int n, a[N][N], dp[N][N], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
        }
    }
    for (int j = 1; j <= n; ++j) ans = max(ans, dp[n][j]);
    cout << ans;
    return 0;
}
