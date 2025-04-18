#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;

const int INF = 1e9 + 7;
const int MAXL = 2e5 + 5;
const int MAXN = 1e5 + 5;
const int MAXA = 2e5 + 5;
const int MAXR = 1e2 + 5;
int n, k, q, L, r, c;
int s[MAXL];
int df[MAXL];
int sii[MAXN];  // S_i 1st element index
int sil[MAXN];  // S_i length
int dp[MAXR][MAXA][2];
vpii mp[MAXA];

void prt(int a[]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sil[i]; j++) {
            cout << a[sii[i] + j] << " ";
        }
        cout << endl;
    }
}
void prtdp(int r) {
    // for (int r = 1; r <= 100; r++) {
    for (int i = 1; i <= 2e5; i++) {
        if (dp[r][i][0]) {
            printf("%d(%d,%d) ", i, dp[r][i][0], dp[r][i][1]);
        }
    }
    cout << endl;
    // }
}

void solve() {
    memset(s, 0, sizeof(s));
    memset(sii, 0, sizeof(sii));
    memset(sil, 0, sizeof(sil));
    memset(dp, 0, sizeof(dp));
    for (auto &v : mp) v.clear();
    cin >> n >> k >> q;
    L = 0;
    for (int i = 1; i <= n; i++) {
        sii[i] = L;
        cin >> sil[i];
        for (int j = 1; j <= sil[i]; j++) {
            cin >> s[++L];
            mp[s[L]].push_back({i, j});
        }
    }
    dp[0][1][0] = dp[0][1][1] = INF;
    for (int r = 1; r <= 100; r++) {
        memset(df, 0, sizeof df);
        for (int a = 1; a <= 2e5; a++) {
            if (dp[r - 1][a][0] > 0) {
                for (auto &p : mp[a]) {
                    int i = p.first, j = p.second;
                    if (dp[r - 1][a][1] == 0 && i == dp[r - 1][a][0]) continue;
                    if (j + 1 <= sil[i]) df[sii[i] + j + 1] += 1;
                    if (j + k <= sil[i]) df[sii[i] + j + k] -= 1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= sil[i]; j++) {
                df[sii[i] + j] += df[sii[i] + j - 1];  // presum
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sil[i]; j++) {
                if (df[sii[i] + j] > 0) {
                    int c = s[sii[i] + j];
                    for (auto &p : mp[c]) {
                        int i = p.first;
                        if (dp[r][c][1] > 0) break;
                        if (dp[r][c][0] > 0) {
                            if (i != dp[r][c][0]) dp[r][c][1] = i;
                        } else {
                            dp[r][c][0] = i;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cin >> r >> c;
        cout << (dp[r][c][0] > 0) << endl;
    }
}

int main() {
    // freopen("./chain/chain3.in", "r", stdin);
    // freopen("./chain/chain3.out", "w", stdout);
    // ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
