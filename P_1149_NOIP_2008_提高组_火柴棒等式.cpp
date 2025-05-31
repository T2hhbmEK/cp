#include <bits/stdc++.h>
#define maxn 11111
using namespace std;

int n, ans;
int dp[maxn + 1] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    cin >> n;
    n -= 4;
    for (int i = 10; i <= maxn; i++) {
        dp[i] = dp[i / 10] + dp[i % 10];
    }
    for (int c = 0; c <= maxn; c++) {
        for (int a = 0; a <= c; a++) {
            int b = c - a;
            if (n == dp[a] + dp[b] + dp[c]) {
                // printf("%d(%d) %d(%d) %d(%d)\n", a, dp[a], b, dp[b], c,
                // dp[c]);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
