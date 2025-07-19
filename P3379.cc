#include <bits/stdc++.h>
using namespace std;

#define MAXN 500010

int n, m, s;
vector<int> e[MAXN];
int pa[MAXN][50], d[MAXN], LOG2[MAXN];

void dfs(int u, int p) {
  pa[u][0] = p;
  for (int i = 0; pa[u][i] != 0; ++i) pa[u][i + 1] = pa[pa[u][i]][i];
  d[u] = d[p] + 1;
  for (int v : e[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
}

void init() {
  dfs(s, 0);
  for (int i = 2; i <= n; ++i) LOG2[i] = LOG2[i / 2] + 1;
}

int LCA(int a, int b) {
  if (d[a] < d[b]) swap(a, b);
  // cerr << format("ab {} {} d {} {}\n", a, b, d[a], d[b]);
  while (d[a] > d[b]) a = pa[a][LOG2[d[a] - d[b]]];
  // cerr << format("ab {} {} d {} {}\n", a, b, d[a], d[b]);
  int x = LOG2[n - 1] + 1;
  while (a != b) {
    if (x != 0 && pa[a][x] == pa[b][x]) {
      x--;
    } else {
      a = pa[a][x], b = pa[b][x];
      // cerr << format("ab {} {} d {} {}\n", a, b, d[a], d[b]);
    }
  }
  return a;
}

void solve() {
  cin >> n >> m >> s;
  for (int i = 1, x, y; i < n; ++i) cin >> x >> y, e[x].push_back(y), e[y].push_back(x);
  init();
  while (m--) {
    int a, b;
    cin >> a >> b;
    cout << LCA(a, b) << "\n";
  }
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
