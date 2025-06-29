#include <iostream>
#include <vector>
#define maxn 1010
#define maxk 110
using namespace std;
int k, n, m, ans, c[maxk], vis[maxk][maxn];
vector<int> e[maxn];
void dfs(int u, int *vis) {
  if (vis[u]) return;
  vis[u] = 1;
  for (int v : e[u]) {
    dfs(v, vis);
  }
}
int main() {
  cin >> k >> n >> m;
  for (int i = 1; i <= k; ++i) cin >> c[i];
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].push_back(v);
  }
  for (int i = 1; i <= k; ++i) dfs(c[i], vis[i]);
  for (int j = 1; j <= n; ++j) {
    int sum = 0;
    for (int i = 1; i <= k; ++i) sum += vis[i][j];
    if (sum == k) ++ans;
  }
  cout << ans << endl;
  return 0;
}
