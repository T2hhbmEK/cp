#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int)(b); ++i)

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

const int MAXN = 1e5;
const int MAXR = 1e2;
const int MAXL = 2e5;
const int MAXV = 2e5;
const int MAXQ = 1e5;

void solve() {
    int n, k, q, l, r, c;
    cin >> n >> k >> q;
    vii s(n);
    vii f(MAXR + 1, vi(MAXV + 1, 0));
    vi d;
    REP(i, n) {
        cin >> l;
        s[i].resize(l, 0);
        d.resize(l, 0);
        REP(j, l) cin >> s[i][j];
    }
    f[0][1] = -1;
    FOR(r, 1, MAXR) REP(i, n) {
        l = s[i].size();
        // reset d to 0
        memset(d.data(), 0, l * sizeof(int));
        REP(j, l) {
            c = s[i][j];
            if (f[r - 1][c] < 0 || (f[r - 1][c] > 0 && f[r - 1][c] != i + 1)) {
                if (j + 1 < l) d[j + 1] += 1;
                if (j + k < l) d[j + k] -= 1;
            }
        }
        FOR(j, 1, l - 1) d[j] += d[j - 1];  // presum
        // REP(j, l) cout << d[j] << " ";
        // cout << endl;
        REP(j, l) {
            c = s[i][j];
            if (d[j] > 0) {
                if (f[r][c] == 0) {
                    f[r][c] = i + 1;
                } else if (f[r][c] > 0 && f[r][c] != i + 1) {
                    f[r][c] = -1;
                }
            }
        }
    }
    // FOR(r, 1, 5) {
    //     FOR(c, 1, MAXV) if (f[r][c] != 0) {
    //         cout << c << "(" << f[r][c] << ")" << " ";
    //     }
    //     cout << endl;
    // }
    while (q--) {
        cin >> r >> c;
        cout << (f[r][c] != 0) << endl;
    }
}

int main() {
    // freopen("./chain/chain6.in", "r", stdin);
    // freopen("./chain/chain6.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
