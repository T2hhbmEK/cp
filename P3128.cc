#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 50010

int n, k;
vector<int> e[MAXN];
int pa[MAXN][20], d[MAXN];
int a[MAXN];

void init(int u, int p) {
  d[u] = d[p] + 1;
  pa[u][0] = p;
  for (int i = 0; pa[u][i]; ++i) pa[u][i + 1] = pa[pa[u][i]][i];
  for (int v : e[u]) {
    if (v == p) continue;
    init(v, u);
  }
}

int lca(int a, int b) {
  if (d[a] < d[b]) swap(a, b);
  while (d[a] > d[b]) a = pa[a][__lg(d[a] - d[b])];
  assert(d[a] == d[b]);
  for (int i = __lg(n - 1) + 1; i >= 0; --i) {
    if (pa[a][i] != pa[b][i]) a = pa[a][i], b = pa[b][i];
  }
  if (a != b) a = pa[a][0], b = pa[b][0];
  return a;
}

void acc(int u, int p) {
  for (int v : e[u]) {
    if (v == p) continue;
    acc(v, u);
    a[u] += a[v];
  }
}

void solve() {
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  init(1, 0);
  while (k--) {
    int s, t;
    cin >> s >> t;
    int r = lca(s, t);
    cerr << format("lca {} {} -> {}\n", s, t, r);
    ++a[s], --a[pa[r][0]];
    ++a[t], --a[r];
  }
  for (int i = 1; i <= n; ++i) cerr << a[i] << " \n"[i == n];
  acc(1, 0);
  for (int i = 1; i <= n; ++i) cerr << a[i] << " \n"[i == n];
  cout << *max_element(a + 1, a + 1 + n) << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
