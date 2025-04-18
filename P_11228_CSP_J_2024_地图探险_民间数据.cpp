#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;

int dr[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int x, y, d;
    cin >> x >> y >> d;
    vii mp(n + 2, vi(m + 2, 0));
    string t;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        for (int j = 1; j <= m; j++) {
            if (t[j - 1] == '.') {
                mp[i][j] = 1;
            }
        }
    }
    mp[x][y] = 2;
    int ans = 1;
    for (int i = 0; i < k; i++) {
        int nx = x + dr[d][0];
        int ny = y + dr[d][1];
        if (mp[nx][ny] == 0) {
            d = (d + 1) % 4;
        } else {
            x = nx, y = ny;
            if (mp[x][y] != 2) {
                mp[x][y] = 2;
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
