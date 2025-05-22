#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2e4 + 5;
int n, L[maxn], R[maxn];
int f[2][2];

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
    }
    f[1][1] = R[1] - 1;
    f[1][0] = R[1] - 1 + R[1] - L[1];
    for (int i = 2, j = i & 1; i <= n; i++, j ^= 1) {
        f[j][0] = min(f[j ^ 1][0] + abs(R[i] - L[i - 1]) + R[i] - L[i] + 1,
                      f[j ^ 1][1] + abs(R[i] - R[i - 1]) + R[i] - L[i] + 1);
        f[j][1] = min(f[j ^ 1][0] + abs(L[i] - L[i - 1]) + R[i] - L[i] + 1,
                      f[j ^ 1][1] + abs(L[i] - R[i - 1]) + R[i] - L[i] + 1);
    }
    int ans = min(f[n & 1][0] + n - L[n], f[n & 1][1] + n - R[n]);
    cout << ans << endl;
    return 0;
}
