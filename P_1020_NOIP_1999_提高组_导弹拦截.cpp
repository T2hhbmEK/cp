#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn], f[maxn], ans;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> a[++n]);
    --n;
    for (int i = 1; i <= n; i++) {
        int j = upper_bound(f + 1, f + 1 + ans, a[i], greater<int>()) - f;
        f[j] = max(f[j], a[i]);
        ans = max(ans, j);
    }
    cout << ans << '\n';
    ans = 0, memset(f, 0x7f, sizeof(f));
    for (int i = 1; i <= n; i++) {
        int j = lower_bound(f + 1, f + 1 + ans, a[i]) - f;
        f[j] = min(f[j], a[i]);
        // for (int j = 1; j <= n; j++) cout << f[j] << " \n"[j == n];
        ans = max(ans, j);
    }
    cout << ans << '\n';
    return 0;
}
