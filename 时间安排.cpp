#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

int n, m, a[maxn], maxa;
ll suma;

bool check(ll x) {
    int cnt = 0;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (sum + a[i] > x) {
            sum = 0;
            cnt += 1;
            if (cnt >= m) {
                return false;
            }
        }
        sum += a[i];
    }
    return cnt < m;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
        suma += a[i];
    }
    ll l = maxa, r = suma;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}
