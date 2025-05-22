#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
using pii = pair<int, int>;
const int dr[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vii a(n + 2, vi(m + 2));
    vector<pair<int, pii>> s;
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j], s.push_back({a[i][j], {i, j}});
    sort(s.begin(), s.end());
    vii d(n + 2, vi(m + 2, 1));
    for (const auto &p : s) {
        int x = p.second.first, y = p.second.second;
        rep(i, 0, 3) {
            int nx = x + dr[i][0];
            int ny = y + dr[i][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m &&
                a[nx][ny] < a[x][y]) {
                d[x][y] = max(d[x][y], d[nx][ny] + 1);
            }
        }
    }
    int ans = 0;
    rep(i, 1, n) rep(j, 1, m) ans = max(ans, d[i][j]);
    cout << ans;
    return 0;
}