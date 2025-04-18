#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n, dp[N], cnt, ans;
void f(int i, int j) {
    // 总共 i 条
    // 每组平行线最多不超过 j 条
    // i >= j >= 1
    if (j > i) {
        return f(i, i);
    }
    if (i == 0) {
        if (dp[cnt] == 0) {
            ans++;
        }
        dp[cnt] = 1;
    }
    for (int k = j; k >= 1; k--) {
        cnt += k * (i - k);
        f(i - k, k);
        cnt -= k * (i - k);
    }
}
int main() {
    cin >> n;
    f(n, n);
    cout << ans << endl;
    return 0;
}