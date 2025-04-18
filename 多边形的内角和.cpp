#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;
void solve() {
    int n;
    cin >> n;
    double ans = 0;
    double s = 1;
    for (int i = 1; i <= n; i++, s = -s) {
        ans += s / i;
    }
    cout << fixed << setprecision(4) << ans << endl;
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
