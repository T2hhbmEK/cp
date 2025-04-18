#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
const int MOD = 1e9 + 7;
const int MAXN = 1e2 + 5;
int n, m, k, stx, sty;
ll a[MAXN][MAXN], b[MAXN][MAXN], ans;
bool vis[MAXN][MAXN], vis2[MAXN][MAXN];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
template <typename T>
void p(T a[MAXN][MAXN]) {
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
void reset() {
    for (int i = 0; i <= n + 1; ++i) {
        memset(b[i], 0, sizeof(b[i]));
        memset(vis2[i], 0, sizeof(vis2[i]));
        // for (int j = 0; j <= m + 1; ++j) {
        //     b[i][j] = vis2[i][j] = 0;
        // }
    }
}
void bfs(int k) {
    a[stx][sty] = 1;
    vis[stx][sty] = 1;
    while (k--) {
        reset();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (vis[i][j] == 1) {
                    for (int l = 0; l < 4; ++l) {
                        int x = i + dir[l][0], y = j + dir[l][1];
                        b[x][y] += a[i][j];
                        vis2[x][y] = 1;
                    }
                }
            }
        }
        for (int i = 0; i <= n + 1; ++i) {
            for (int j = 0; j <= m + 1; ++j) {
                if (b[i][j]) b[i][j] %= MOD;
            }
        }
        // p(b);
        // p(vis2);
        swap(a, b);
        swap(vis, vis2);
        for (int i = 0; i <= n + 1; ++i) {
            ans += a[i][0] + a[i][m + 1];
        }
        for (int j = 1; j <= m; ++j) {
            ans += a[0][j] + a[n + 1][j];
        }
        ans %= MOD;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k >> stx >> sty;
    stx++, sty++;
    bfs(k);
    cout << ans;
    return 0;
}
