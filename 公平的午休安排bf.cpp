#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MAXV = 1e4 + 5;
const int INF = 0x3f3f3f3f;

int n, a[MAXN], sum;
int ans = INF;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int m = 1 << n;
    for (int i = 0; i < m; i++) {
        int sum1 = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum1 += a[j + 1];
            }
        }
        ans = min(ans, max(sum1, sum - sum1));
    }
    cout << ans;
    return 0;
}
