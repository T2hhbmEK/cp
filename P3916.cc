#include <iostream>
#include <vector>
#define maxn 100010
using namespace std;
int n, m, dp[maxn];
vector<int> e[maxn];
void dfs(int u, int mx) {
  if (dp[u] >= mx) return;
  dp[u] = mx;
  for (int v : e[u]) dfs(v, mx);
}
int main() {
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    e[v].push_back(u);
  }
  for (int i = n; i >= 1; --i) dfs(i, i);
  for (int i = 1; i <= n; ++i) cout << dp[i] << " \n"[i == n];
  return 0;
}
