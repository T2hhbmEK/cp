#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define maxn 110
#define inf 0x3f3f3f3f
using namespace std;
int n, w[maxn], u, v, ans = inf;
bool vis[maxn];
vector<int> edges[maxn];
void add_edge(int u, int v) {
  if (u != 0 && v != 0) edges[u].push_back(v), edges[v].push_back(u);
}
void dfs(int k, int d, int& sum) {
  sum += w[k] * d;
  vis[k] = true;
  for (int i : edges[k]) {
    if (!vis[i]) {
      dfs(i, d + 1, sum);
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i] >> u >> v;
    add_edge(i, u), add_edge(i, v);
  }
  for (int i = 1; i <= n; ++i) {
    memset(vis, 0, sizeof(vis));
    int sum = 0;
    dfs(i, 0, sum);
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
