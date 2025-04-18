#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
// #define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
void print(vector<int> a) {
    for (auto x : a) cout << x << ' ';
    cout << endl;
}
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    vector<int> c(n + 1, m + 1);
    for (int i = 1; i <= m; ++i) {
        if (c[b[i]] > m) c[b[i]] = i;
    }
    // print(c);
    bool ok = 1;
    for (int i = 1; i < n; ++i) {
        if (c[a[i]] > c[a[i + 1]]) {
            ok = 0;
            break;
        }
    }
    if (ok) {
        cout << "YA" << endl;
    } else {
        cout << "TIDAK" << endl;
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
