#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 5;
const int maxl = 5e4 + 5;

int n, W, w[maxn], v[maxn], dp[maxn][maxl];

int main() {
    cin >> n >> W;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = w[i]; j <= W; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[n][W];
    return 0;
}
