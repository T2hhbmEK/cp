#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m;
    cin >> t >> n >> m;
    vector<int> w(n + 1), v(n + 1);
    w[0] = v[0] = 1; // let 0th item be the gold coin
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    t--;
    while (t--) {
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
        }
        for (int i = 0; i <= n; ++i) { // dp
            for (int j = w[i]; j <= m; ++j) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        m = dp[m];
        swap(v, w);
    }
    cout << m << endl;
    return 0;
}
