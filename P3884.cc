#include <algorithm>
#include <iostream>
#include <utility>
#define maxn 110
using namespace std;
int n, u, v, depth[maxn], ch[maxn][2], pa[maxn];
int max_depth, width[maxn];
void add_edge(int u, int v) {
  ch[u][ch[u][0] != 0] = v;
  pa[v] = u;
}
bool vis[maxn];
void dfs(int u, int d) {
  depth[u] = d;
  width[d]++;
  max_depth = max(max_depth, d);
  vis[u] = true;
  for (auto v : ch[u]) {
    if (v != 0 && !vis[v]) {
      dfs(v, d + 1);
    }
  }
}
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  while (depth[u] > depth[v]) u = pa[u];
  while (u != v) u = pa[u], v = pa[v];
  return u;
}
int dis(int a, int u) {
  if (a == u) return 0;
  return 1 + dis(a, pa[u]);
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    add_edge(u, v);
  }
  cin >> u >> v;
  dfs(1, 1);
  int a = lca(u, v);
  int ans = dis(a, u) * 2 + dis(a, v);
  cout << max_depth << endl;
  cout << *max_element(width + 1, width + 1 + max_depth) << endl;
  cout << ans << endl;
  return 0;
}
