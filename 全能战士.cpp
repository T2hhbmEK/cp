#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int LINF = 1e18 + 7;
const int MAXN = 3e5 + 7;
const int MAXM = 1e9;
ll n, m, a[MAXN], b[MAXN];
bool check(ll x) {
    ll cnt = 0;
    for (ll i = 1; i <= n; ++i) {
        if (b[i] >= a[i]) {
            cnt += x / b[i];
            if (x % b[i] != 0) cnt += 1;
        } else if (a[i] * m >= x) {
            cnt += x / a[i];
            if (x % a[i] != 0) cnt += 1;
        } else {
            cnt += m;
            ll y = x - a[i] * m;
            cnt += y / b[i];
            if (y % b[i] != 0) cnt += 1;
        }
        if (cnt > n * m) {
            return 0;
        }
    }
    return 1;
}
int main() {
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    ll l = 1, r = LINF;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}