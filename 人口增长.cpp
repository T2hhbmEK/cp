#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;
void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    while (m--) {
        int nn = (n + k + 1) / 2;
        if (nn == n) break;
        n = nn;
    }
    cout << n << endl;
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
