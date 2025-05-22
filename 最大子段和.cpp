#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int dp[N];

int main() {
    int n, ans, a;
    cin >> n;
    cin >> dp[1];  // 边界, dp[1] = a[1]
    ans = dp[1];   // ans为dp[i]的最大值, 初始值为dp[1]
    for (int i = 2; i <= n; ++i) {
        cin >> a;
        dp[i] = max(dp[i - 1] + a, a);  // 状态转移方程
        ans = max(ans, dp[i]);          // 更新ans
    }
    cout << ans;
    return 0;
}
