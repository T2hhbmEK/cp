#include <bits/stdc++.h>
#define MAXN 5000010
#define MAXBITS 30
using namespace std;
int n;
unordered_map<int, int> e[MAXN];
bool vis[MAXN], exist[MAXN];
int nex[MAXN][2], cnt;
void add(int x) {
  int u = 0;
  for (int i = MAXBITS; i >= 0; --i) {
    int j = (x >> i) & 1;
    if (nex[u][j] == 0) nex[u][j] = ++cnt;
    u = nex[u][j];
  }
  exist[u] = true;
}
void dfs(int u, int sum) {
  if (vis[u]) return;
  vis[u] = true;
  add(sum);
  for (auto& [v, w] : e[u]) {
    dfs(v, sum ^ w);
  }
}
int ans;
void trie_dfs(int u, int x) {
  if (exist[u]) {
    int v = 0, y = 0;
    for (int i = MAXBITS; i >= 0; --i) {
      int j = ((x >> i) & 1) ^ 1;
      if (nex[v][j] == 0) j ^= 1;
      v = nex[v][j];
      y = (y << 1) | j;
    }
    assert(exist[v]);
    ans = max(ans, x ^ y);
  }
  for (int i = 0; i < 2; ++i) {
    int v = nex[u][i];
    if (v != 0) trie_dfs(v, (x << 1) | i);
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n;
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    e[u][v] = e[v][u] = w;
  }
  dfs(1, 0);
  trie_dfs(0, 0);
  cout << ans << '\n';
  return 0;
}
