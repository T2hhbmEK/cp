#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
const int MOD = 80112002;

int dfs(int k, const vii &ch, vi &f) {
    if (f[k] > 0) return f[k];
    if (ch[k].size() == 0) return (f[k] = 1);
    for (int i : ch[k]) {
        f[k] += dfs(i, ch, f);
        f[k] %= MOD;
    }
    return f[k];
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vii ch(n + 1), pa(n + 1);
    // a <-- b <-- c
    rep(i, 1, m) {
        int a, b;
        cin >> a >> b;
        ch[b].push_back(a);
        pa[a].push_back(b);
    }
    int ans = 0;
    vi f(n + 1);
    rep(i, 1, n) {
        dfs(i, ch, f);
        if (pa[i].size() == 0) {
            ans += f[i];
            ans %= MOD;
        }
    }
    cout << ans;
    return 0;
}
