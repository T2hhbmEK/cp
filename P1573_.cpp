#include <bits/stdc++.h>
using namespace std;
#define N 1000007
int idx[2][N], dp[2][N], n;
int _mod(int x) {
    return x % 1000007;
}
int _modN(int x) {
    return x % N;
}
int g(int x) {
    int mx = _modN(x);
    if (idx[0][mx] != x) {
        dp[0][mx] = _mod(2 * g(x - 1) + 1);
        idx[0][mx] = x;
    }
    return dp[0][mx];
}
int f(int x) {
    int mx = _modN(x);
    if (idx[1][mx] != x) {
        int j = sqrt(static_cast<double>(x) * 2 + 0.25) - 1.5;
        dp[1][mx] = _mod(2 * f(x - j - 1) + 2 * g(j) + 1);
        idx[1][mx] = x;
    }
    return dp[1][mx];
}
int main() {
    cin >> n;
    dp[0][0] = 0;
    dp[1][0] = 0;
    int c = 0;
    int j = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = f(i);
    }
    cout << ans << endl;
    return 0;
}
// while (j <= n) {
//     for (int k = 1; k <= c + 1 && j <= n; ++k) {
//         jj[j++] = c;
//     }
//     ++c;
// }
// dp[0][i] = _mod(dp[0][i - 1] * 2 + 1);
// int j = jj[i];
// dp[1][i] = _mod(dp[1][i - j - 1] * 2 + dp[0][j] * 2 + 1);
// printf("f(%d)=2f(%d)+2g(%d)+1=%d\n", i, i - 1 - j, j, dp[1][i]);

// dp[1][i] = INT_MAX;
// int mj = 0;
// for (int j = 0; j <= i - 1; ++j) {
//     int fi = dp[1][j] * 2 + dp[0][i - j - 1] * 2 + 1;
//     if (fi < dp[1][i]) {
//         dp[1][i] = fi;
//         mj = j;
//     }
// }
// printf("f(%d)=2f(%d)+2g(%d)+1\n", i, mj, i - 1 - mj);