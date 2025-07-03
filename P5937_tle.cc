#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
unordered_map<int, unordered_map<int, int>> e;
int dfs(int u, int v, unordered_set<int>& vis) {
  vis.insert(u);
  if (u == v) return 0;
  if (e[u].contains(v)) return e[u][v];
  for (auto& [w, k] : e[u]) {
    if (vis.contains(w)) continue;
    int x = dfs(w, v, vis);
    if (x != -1) return x ^ k;
  }
  return -1;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    int k;
    string s;
    cin >> u >> v >> s, ++v, k = (s == "odd");
    unordered_set<int> vis;
    int kk = dfs(u, v, vis);
    // cerr << u << " " << v << " " << k << " " << kk << endl;
    if (kk != -1 && kk != k) break;
    e[u][v] = e[v][u] = k;
    ans = i;
  }
  cout << ans << endl;
  return 0;
}
