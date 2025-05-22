#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio cin.tie(nullptr)->sync_with_stdio(false)
// #define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;

const int maxn = 1005;
int n, x;
int lose[maxn], win[maxn], use[maxn];
int f[maxn];

signed main() {
    scanf("%d%d", &n, &x);
    rep(i, 1, n) scanf("%d%d%d", &lose[i], &win[i], &use[i]);
    rep(i, 1, n) per(j, x, 0) {
        if (j >= use[i]) {
            f[j] = max(f[j] + lose[i], f[j - use[i]] + win[i]);
        } else {
            f[j] += lose[i];
        }
    }
    printf("%lld", f[x] * 5ll);
    return 0;
}
