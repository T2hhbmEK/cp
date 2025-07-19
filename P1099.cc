#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define INF 0x3f3f3f3f
#define MAXN 310

int n, s;
unordered_map<int, int> e[MAXN];
int vis[MAXN];

void input() {
  cin >> n >> s;
  for (int i = 1, u, v, w; i < n; ++i) cin >> u >> v >> w, e[u][v] = w, e[v][u] = w;
}

pair<int, int> dfs(int u) {
  vis[u] = 1;
  int p = u, d = 0;
  for (auto [v, w] : e[u]) {
    if (vis[v]) continue;
    auto [pp, dd] = dfs(v);
    dd += w;
    if (dd > d) p = pp, d = dd;
  }
  return {p, d};
}

void dfs1(int u, int q, vector<int>& a) {
  if (vis[u]) return;
  vis[u] = 1;
  if (u == q) {
    a.push_back(u);
    return;
  }
  for (auto [v, w] : e[u]) {
    dfs1(v, q, a);
    if (!a.empty()) {
      a.push_back(u);
      return;
    }
  }
}

int D[MAXN];
void dfs2(int u, int sum) {
  if (vis[u]) return;
  D[u] = min(D[u], sum);
  vis[u] = 1;
  for (auto [v, w] : e[u]) dfs2(v, D[u] + w);
}

void solve() {
  input();
  auto [p, dp] = dfs(1);
  memset(vis, 0, sizeof(vis));
  auto [q, dq] = dfs(p);
  memset(vis, 0, sizeof(vis));
  vector<int> a;
  dfs1(p, q, a);
  int ans = INF;
  for (int i = 0; i < sz(a); ++i) {
    int sum = 0;
    for (int j = i; j < sz(a) && sum <= s; ++j) {
      memset(vis, 0, sizeof(vis));
      memset(D, 0x3f, sizeof(D));
      for (int k = i; k <= j; ++k) D[a[k]] = 0;
      dfs2(a[i], 0);
      // for (int k = i; k <= j; ++k) cerr << a[k] << " \n"[k == j];
      // for (int k = 1; k <= n; ++k) cerr << D[k] << " \n"[k == n];
      int d = *max_element(D + 1, D + 1 + n);
      // cout << sum << " " << d << "\n";
      ans = min(ans, d);
      if (j + 1 < sz(a)) sum += e[a[j]][a[j + 1]];
    }
  }
  cout << ans << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
