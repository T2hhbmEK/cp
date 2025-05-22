#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
// #define int long long
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define debug(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define repa(i, a, n) for (int i = a; i <= (int)(n); ++i)
#define repd(i, a, n) for (int i = a; i >= (int)(n); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const double PI = acos(-1);
const ll MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

int n, m, ans;
vector<string> a;
vii vis;
int dr[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int x, int y) {
    vis[x][y] = 1;
    rep(k, 4) {
        int nx = x + dr[k][0], ny = y + dr[k][1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (vis[nx][ny] || a[nx][ny] == '0') continue;
        dfs(nx, ny);
    }
}

void solve() {
    cin >> n >> m;
    a = vector<string>(n);
    vis = vii(n, vi(m));
    rep(i, n) cin >> a[i];
    rep(i, n) rep(j, m) {
        if (a[i][j] == '0' || vis[i][j]) continue;
        dfs(i, j);
        ans++;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
