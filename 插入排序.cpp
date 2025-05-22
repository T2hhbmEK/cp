#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 8192;
int n, q, rnk[N];
struct T {
    int v, i;
} a[N];

bool cmp(T x, T y) {
    if (x.v != y.v) return x.v < y.v;
    return x.i < y.i;
}

void solve() {
    int op, x, v;
    cin >> op >> x;
    if (op == 1) {
        cin >> v;
        a[rnk[x]].v = v;
        for (int i = rnk[x]; i >= 2 && cmp(a[i], a[i - 1]); i--) {
            swap(rnk[a[i].i], rnk[a[i - 1].i]);
            swap(a[i], a[i - 1]);
        }
        for (int i = rnk[x]; i <= n - 1 && cmp(a[i + 1], a[i]); i++) {
            swap(rnk[a[i].i], rnk[a[i + 1].i]);
            swap(a[i], a[i + 1]);
        }
    } else {
        cout << rnk[x] << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].v;
        a[i].i = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        rnk[a[i].i] = i;
    }
    while (q--) {
        solve();
    }
    return 0;
}
