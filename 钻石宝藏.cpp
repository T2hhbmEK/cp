#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int maxl = 1e5 + 5;

int n, W, w[maxn], v[maxn], dp[maxl];

int main() {
    cin >> n >> W;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = W; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W];
    return 0;
}
