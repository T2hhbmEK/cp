#include <bits/stdc++.h>
#define maxn 20
using namespace std;

int n, dp[maxn] = {1, 1};

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    cout << dp[n] << endl;
    return 0;
}
