#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
// #define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
using VT = vector<int>;
using VTT = vector<VT>;
using VTTT = vector<VTT>;
void solve() {
    int n, m;
    cin >> n >> m;
    int maxk = (int)log2(n) + 1;
    VTT a(n + 2, VT(m + 2, 0));
    VTT pre(n + 2, VT(m + 2, 0));
    VTTT fmax(n + 2, VTT(m + 2, VT(maxk, 0)));
    VTTT fmin(n + 2, VTT(m + 2, VT(maxk, 0)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            fmax[i][j][0] = fmin[i][j][0] = pre[i][j];
            pre[i][j] = pre[i][j - 1] + a[i][j];
        }
    }
    auto blt_st = [&](VTT& st, auto op) {
        for (int k = 1; k <= maxk; k++) {
            int len = 1 << k;
            for (int j = 1; j + len - 1 <= m; j++) {
                st[j][k] = op(st[j][k - 1], st[j + (len >> 1)][k - 1]);
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        blt_st(fmax[i], [](int a, int b) { return max(a, b); });
        blt_st(fmin[i], [](int a, int b) { return min(a, b); });
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
