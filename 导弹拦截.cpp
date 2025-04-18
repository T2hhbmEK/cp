#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;

int n, h[N], dp[N], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];  // 输入
    dp[n] = 1;  // 最后一枚导弹开始，最多拦截一枚
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = 1;  // 第i枚导弹开始，至少能拦截一枚
        for (int j = i + 1; j <= n; j++) {
            if (h[i] >= h[j]) {
                dp[i] = max(dp[i], dp[j] + 1);  // 找到最大的dp[j] + 1赋给dp[i]
            }
        }
    }
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);  // 找到最大的dp[i]
    cout << ans;
    return 0;
}
