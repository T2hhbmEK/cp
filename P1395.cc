#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f
#define MAXN 50010

int n;
vector<int> e[MAXN];

int d_up[MAXN], d_down[MAXN], n_sons[MAXN];

void dfs(int u, int pa) {
  for (auto v : e[u]) {
    if (v == pa) continue;
    dfs(v, u);
    d_down[u] += d_down[v] + n_sons[v] + 1;
    n_sons[u] += n_sons[v] + 1;
  }
}

void dfs2(int u, int pa) {
  if (pa != 0) {
    d_up[u] += d_up[pa] + (n - n_sons[pa] - 1);
    d_up[u] += (d_down[pa] - d_down[u] - n_sons[u] - 1) + (n_sons[pa] + 1 - (n_sons[u] + 1));
  }
  for (auto v : e[u]) {
    if (v == pa) continue;
    dfs2(v, u);
  }
}

void solve() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
  dfs(1, 0);
  // for (int i = 1; i <= n; ++i) cerr << n_sons[i] << " \n"[i == n];
  // for (int i = 1; i <= n; ++i) cerr << d_down[i] << " \n"[i == n];
  dfs2(1, 0);
  // for (int i = 1; i <= n; ++i) cerr << d_up[i] << " \n"[i == n];
  int ans = INF, x;
  for (int i = 1; i <= n; ++i) {
    if (d_down[i] + d_up[i] < ans) ans = d_down[i] + d_up[i], x = i;
  }
  cout << x << " " << ans << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
