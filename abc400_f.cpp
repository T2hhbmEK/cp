#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)

const int N = 405;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, c[2 * N], x[N], ans;
int dp[2 * N][2 * N], dd[2 * N][2 * N];
inline void chmin(int &a, int b) {
    a = min(a, b);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    rep(i, 1, n) cin >> c[i], c[i + n] = c[i];
    rep(i, 1, n) cin >> x[i];
    per(l, 2 * n, 1) rep(r, l + 1, 2 * n) {
        dd[l][r] = dp[l][r] = INF;
        if (c[l] == c[r - 1]) chmin(dd[l][r], dd[l][r - 1]);
        rep(m, l + 1, r - 1) {
            chmin(dp[l][r], dp[l][m] + dp[m][r]);
            chmin(dd[l][r], dd[l][m] + dp[m][r]);
        }
        chmin(dp[l][r], dd[l][r] + r - l + x[c[l]]);
        // printf("%lld %lld %lld %lld\n", l, r, dd[l][r], dp[l][r]);
    }
    ans = INF;
    rep(l, 1, n) chmin(ans, dp[l][l + n]);
    cout << ans;
    return 0;
}
