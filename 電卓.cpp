#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
// #define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
void solve() {
    int x, y;
    cin >> x >> y;
    if (y == 0) {
        cout << "ERROR" << endl;
    } else {
        double ans = (double)x / y;
        ans = floor(ans * 100) / 100;
        cout << fixed << setprecision(2) << ans << endl;
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
