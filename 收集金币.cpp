#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
const int inf = 0x3f3f3f3f;
const int maxn = 2e4 + 5;
int a[maxn];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int a_min = inf, a_max = -inf;
    for (int i = 1; i <= n; i++) {
        if (a[i] < a_min) {
            a_min = a[i];
        }
        if (a[i] > a_max) {
            a_max = a[i];
        }
    }
    bool flag = a_min * a_max >= 0;
    a_min = abs(a_min);
    a_max = abs(a_max);
    if (a_min > a_max) swap(a_min, a_max);
    if (flag) a_min = 0;
    int ans = a_min * 2 + a_max;
    cout << ans << endl;
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
