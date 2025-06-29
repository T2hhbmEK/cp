#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;
constexpr int maxn = 20010;
unordered_map<int, int> e[maxn];
int f[maxn];
int n, m;
bool dfs(int u, int x, int k) {
  f[u] = x;
  for (auto& [v, c] : e[u]) {
    if (c <= k) continue;
    if (f[v] < 0) {
      if (!dfs(v, x ^ 1, k)) return false;
    } else {
      if (f[v] == f[u]) return false;
    }
  }
  return true;
}
bool chk(int k) {
  memset(f, -1, sizeof(f));
  for (int i = 1; i <= n; ++i) {
    if (f[i] < 0) {
      if (!dfs(i, 0, k)) return false;
    }
  }
  return true;
};
int main() {
  cin >> n >> m;
  int lo = 0, hi = 0;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    e[a][b] = e[b][a] = c;
    hi = max(hi, c);
  }
  while (lo < hi) {
    int mi = (lo + hi) >> 1;
    if (chk(mi)) {
      hi = mi;
    } else {
      lo = mi + 1;
    }
  }
  cout << lo << endl;
  return 0;
}
