#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;

int lowbit(int x) {
    return x & -x;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int t = lowbit(a[i]);
        pre[i] = pre[i - 1] + t;
        a[i] /= t;
    }
    int q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        int i = lower_bound(pre.begin(), pre.end(), x) - pre.begin();
        cout << a[i] << endl;
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
