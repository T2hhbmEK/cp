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
    int n, k, q;
    cin >> n >> k >> q;
    vii s(n);
    vii f(MAXR + 1, vi(MAXV + 1, 0));
    REP(i, n) {
        int l;
        cin >> l;
        s[i].resize(l, 0);
        REP(j, l) cin >> s[i][j];
    }
    f[0][1] = -1;
    FOR(r, 1, MAXR) REP(i, n) {
        int l = s[i].size();
        int last = -1;
        REP(j, l) {
            int c = s[i][j];
            if (j <= last) {
                if (f[r][c] == 0) {
                    f[r][c] = i + 1;
                } else if (f[r][c] > 0 && f[r][c] != i + 1) {
                    f[r][c] = -1;
                }
            }
            if (f[r - 1][c] < 0 || (f[r - 1][c] > 0 && f[r - 1][c] != i + 1)) {
                last = j + k - 1;
            }
        }
    }
    while (q--) {
        int r, c;
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
