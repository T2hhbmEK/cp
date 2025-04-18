#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
// #define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
void print(set<int> a) {
    for (auto x : a) cout << x << ' ';
    cout << endl;
}
void print(vector<int> a) {
    for (auto x : a) cout << x << ' ';
    cout << endl;
}
void print(vector<deque<int>> &c) {
    int n = c.size() - 2;
    for (int i = 1; i <= n; ++i) {
        cout << "q[" << i << "] ";
        for (auto x : c[i]) cout << x << ' ';
        cout << endl;
    }
}
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1), a2i(n + 1), b(m + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a2i[a[i]] = i;
    }
    for (int i = 1; i <= m; ++i) cin >> b[i];
    vector<deque<int>> c(n + 2);
    for (int i = 1; i <= m; ++i) {
        c[b[i]].push_back(i);
    }
    c[0].push_back(0);
    for (int i = 1; i <= n + 1; ++i) c[i].push_back(m + 1);
    vector<int> nop(n);
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        nop[i] = c[a[i]].front() > c[a[i + 1]].front();
        ans += nop[i];
    }
    cout << (ans == 0 ? "YA" : "TIDAK") << endl;
    // print(c);
    // print(b);
    // print(nop);
    // cout << ans << endl;
    while (q--) {
        int s, t;
        cin >> s >> t;  // b[s] = t
        if (b[s] != t) {
            auto it = lower_bound(c[b[s]].begin(), c[b[s]].end(), s);
            if (it != c[b[s]].end() && *it == s) c[b[s]].erase(it);
            c[t].insert(lower_bound(c[t].begin(), c[t].end(), s), s);
            int i1 = a2i[b[s]];
            int i2 = a2i[t];
            b[s] = t;
            for (int i : {i1 - 1, i1, i2 - 1, i2}) {
                if (i < 1 || i >= n) continue;
                int nn = c[a[i]].front() > c[a[i + 1]].front();
                ans += nn - nop[i];
                nop[i] = nn;
            }
        }
        cout << (ans == 0 ? "YA" : "TIDAK") << endl;
        // print(c);
        // print(b);
        // print(nop);
        // cout << ans << endl;
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
