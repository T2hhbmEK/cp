#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

#define int long long
#define sz(x) (int)(x).size()
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using pq = priority_queue<int, vi, greater<>>;
istream& operator>>(istream& is, __int128& x);
ostream& operator<<(ostream& os, __int128 x);
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int MAXN = 500 + 10;
constexpr int MOD = 998244353;

int n, m, k, t, q;
set<int> d;
int f[MAXN][MAXN];

void show() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cerr << (f[i][j] == INF ? -1 : f[i][j]) << ' ';
    }
    cerr << '\n';
  }
  cerr << '\n';
}

void floyd() {  // floyd O(n^3)
  for (int kk = 1; kk <= n; kk++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        f[i][j] = min(f[i][j], f[i][kk] + f[kk][j]);
      }
    }
  }
  // show();
}

int dis[MAXN], vis[MAXN];
void dijkstra(int s) {  // O(n^2)
  for (int i = 1; i <= n; ++i) dis[i] = INF, vis[i] = 0;
  dis[s] = 0;
  for (int i = 1; i <= n; i++) {
    int u = 0, mind = INF;
    for (int j = 1; j <= n; j++) {
      if (!vis[j] && dis[j] < mind) u = j, mind = dis[j];
    }
    if (u == 0) break;
    vis[u] = 1;
    for (int v = 1; v <= n; v++) {
      if (f[u][v] == INF || vis[v]) continue;
      dis[v] = min(dis[v], dis[u] + f[u][v]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      f[i][j] = min(f[i][j], dis[i] + dis[j]);
    }
  }
  // show();
}

void solve() {  //
  d.clear();
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) f[i][j] = INF;
    f[i][i] = 0;
  }
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    f[a][b] = f[b][a] = min(f[a][b], c);
  }
  cin >> k >> t;
  for (int i = 1; i <= k; ++i) {
    int x;
    cin >> x;
    d.insert(x);
  }
  for (auto a : d) {
    for (auto b : d) {
      f[a][b] = f[b][a] = min(f[a][b], t);
    }
  }
  floyd();
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int a, b, c;
      cin >> a >> b >> c;
      if (f[a][b] > c) {
        f[a][b] = f[b][a] = c;
        dijkstra(a);
        // floyd();
      }
    } else if (op == 2) {
      int x;
      cin >> x;
      if (!d.contains(x)) {
        for (int a : d) {
          f[a][x] = f[x][a] = min(f[a][x], t);
        }
        dijkstra(x);
        // floyd();
        d.insert(x);
      }
    } else {
      int sum = 0;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (f[i][j] != INF) sum += f[i][j];
        }
      }
      cout << sum << '\n';
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}

istream& operator>>(istream& is, __int128& x) {
  bool neg = false;
  char ch = 0;
  x = 0;
  while (!isdigit(ch)) neg ^= ch == '-', ch = is.get();
  while (isdigit(ch)) x = (x << 3) + (x << 1) - (ch & 0xF), ch = is.get();
  if (!neg) x = -x;
  return is;
}

ostream& operator<<(ostream& os, __int128 x) {
  static char s[40];
  signed n = 0;
  if (x == 0) return os << 0;
  x = x < 0 ? (os << '-', x) : -x;
  while (x) s[n++] = '0' - x % 10, x /= 10;
  while (n) os.put(s[--n]);
  return os;
}
