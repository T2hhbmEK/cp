#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
struct T {
    int i, m;
} a[maxn];
bool cmp(T x, T y) { return x.m < y.m; }
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].m;
        a[i].i = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    int q;
    cin >> q;
    while (q--) {
        T x;
        cin >> x.m;
        int l = lower_bound(a + 1, a + 1 + n, x, cmp) - a;
        if (l <= n && a[l].m == x.m) {
            cout << a[l].i << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
