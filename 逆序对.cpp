#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const int NMAX = 5e3 + 5;

ll n, k, a[NMAX], cnt_inner, cnt_inter, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (ll i = 0; i < n; ++i) cin >> a[i];
    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) ++cnt_inner;
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (a[i] > a[j]) ++cnt_inter;
        }
    }
    ans += k * cnt_inner;
    ans += (k * (k - 1) / 2) * cnt_inter;
    cout << ans;
    return 0;
}
