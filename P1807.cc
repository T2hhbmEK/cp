#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;
constexpr int inf = 0x3f3f3f3f;
constexpr int maxn = 1510;
int n, m;
unordered_map<int, int> e[maxn];
int dp[maxn];
int vis[maxn];  // 0 to visit, 1 visiting, 2 visited
int dfs(int u) {
  if (vis[u] == 2) return dp[u];
  assert(vis[u] != 1);
  vis[u] = 1;
  for (auto& [v, w] : e[u]) {
    int dv = dfs(v);
    if (dv != -inf) dp[u] = max(dp[u], dv + w);
  }
  vis[u] = 2;
  return dp[u];
}
int main() {
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    if (!e[u].contains(v) || (e[u].contains(v) && w > e[u][v])) e[u][v] = w;
  }
  fill(dp + 1, dp + 1 + n, -inf);
  vis[n] = 2, dp[n] = 0;
  int ans = dfs(1);
  cout << (ans == -inf ? -1 : ans) << endl;
  return 0;
}
