#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, d;
    cin >> n >> d;
    vector<int> v(n, 0), a(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        cin >> v[i];
        v[i] += v[i - 1];  // presum
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int m = 1;
    int f = 0, ans = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[m]) m = i;
        int x = (v[i] - f * d + d - 1) / d;
        if (x <= 0) continue;
        f += x;
        ans += x * a[m];
    }
    cout << ans << endl;
    return 0;
}
