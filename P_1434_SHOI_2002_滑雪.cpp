#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int MAXN = 105;
int n, m;
int h[MAXN][MAXN];
pii pos[MAXN * MAXN];
int f[MAXN][MAXN];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> h[i][j];
            pos[++cnt] = {i, j};
        }
    }
    sort(pos + 1, pos + cnt + 1, [](const pii &a, const pii &b) {
        return h[a.first][a.second] > h[b.first][b.second];
    });
    for (int i = 1; i <= cnt; i++) {
        int x = pos[i].first, y = pos[i].second;
        f[x][y] = 1;
        for (int j = 0; j < 4; j++) {
            int nx = x + dir[j][0], ny = y + dir[j][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (h[nx][ny] <= h[x][y]) continue;
            f[x][y] = max(f[x][y], f[nx][ny] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
