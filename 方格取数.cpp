#include <bits/stdc++.h>
using namespace std;
const int N = 105;

int n, a[N][N], dp[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + a[i][j];
        }
    }
    cout << dp[n][n];
    return 0;
}
