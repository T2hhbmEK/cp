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

struct Pos {
    int x, y, d;
};

const int n = 100, m = 100;
vii vis;
const vector<pii> dr = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},     // 马走日
                        {2, -1}, {1, -2}, {-1, -2}, {-2, -1},   // 马走日
                        {-2, 2}, {2, 2},  {2, -2},  {-2, -2}};  // 马走田
queue<Pos> q;

void test_dr() {
    vii a(5, vi(5));
    for (auto& d : dr) a[d.first + 2][d.second + 2] = 1;
    rep(i, 5) rep(j, 5) cout << a[i][j] << " \n"[j == 4];
}

int bfs(int x, int y) {
    vis = vii(n + 2, vi(m + 2));
    q = queue<Pos>();
    vis[x][y] = 1;
    if (x == 1 && y == 1) return 0;
    q.push({x, y, 0});
    while (!q.empty()) {
        Pos p = q.front();
        q.pop();
        for (auto& d : dr) {
            int nx = p.x + d.first, ny = p.y + d.second;
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                // printf("(%d,%d)->(%d,%d) %d\n", p.x, p.y, nx, ny, p.d + 1);
                if (nx == 1 && ny == 1) return p.d + 1;
                q.push({nx, ny, p.d + 1});
            }
        }
    }
    return -1;
}

void solve() {
    int x, y;
    cin >> x >> y;
    cout << bfs(x, y) << endl;
    cin >> x >> y;
    cout << bfs(x, y) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    // test_dr(), exit(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
