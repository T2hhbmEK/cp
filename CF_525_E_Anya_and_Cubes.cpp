#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e16 + 7;
const int maxn = 30;

int n, k, a[maxn], hf, ans;
int S, fa[maxn];
map<pair<int, int>, int> mp;

void dfsa(int i, int j, int s) {
    if (s > S || j > k) return;
    if (i > hf) {
        mp[{j, s}]++;
        return;
    }
    dfsa(i + 1, j + 1, s + fa[i]);
    dfsa(i + 1, j, s + a[i]);
    dfsa(i + 1, j, s);
}

void dfsb(int i, int j, int s) {
    if (s > S || j > k) return;
    if (i > n) {
        for (int u = 0; u <= k - j; u++) {
            if (mp.find({u, S - s}) != mp.end()) {
                ans += mp[{u, S - s}];
            }
        }
        return;
    }
    dfsb(i + 1, j + 1, s + fa[i]);
    dfsb(i + 1, j, s + a[i]);
    dfsb(i + 1, j, s);
}

int fac(int x) {
    int ret = 1;
    for (; x; ret *= x--) {
        if (ret > S / x) return inf;
    }
    return ret;
}

signed main() {
    cin >> n >> k >> S;
    hf = n / 2;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) fa[i] = fac(a[i]);
    dfsa(1, 0, 0);
    dfsb(hf + 1, 0, 0);
    cout << ans << endl;
    return 0;
}
