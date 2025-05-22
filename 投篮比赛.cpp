#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#define int long long
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int)(b); ++i)

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;

void solve() {
    int n = 3, sum = 0;
    vi a(n);
    REP(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    int ans = 0;
    REP(i, n) {
        if (a[i] > sum - a[i]) ans++;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
