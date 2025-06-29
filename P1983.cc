#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define maxn 1005
using namespace std;
int n, m, ans;
unordered_map<int, vector<int>> e;
bool adj[maxn][maxn];
void TopoSort() {
  unordered_map<int, pair<int, int>> d;
  for (int i = 1; i <= n; ++i) d[i] = {0, 0};
  for (auto& [u, vs] : e) {
    d[u].second += vs.size();
    for (auto& v : vs) {
      d[v].first += 1;
    }
  }
  queue<pair<int, int>> q;
  unordered_set<int> vis;
  for (auto& [u, p] : d) {
    if (p.first == 0) q.push({u, 1});
  }
  while (!q.empty()) {
    auto& [u, k] = q.front();
    ans = max(ans, k);
    vis.insert(u);
    q.pop();
    for (auto& v : e[u]) {
      d[v].first -= 1;
      if (d[v].first == 0 && !vis.contains(v)) q.push({v, k + 1});
    }
  }
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  while (m--) {
    int s;
    cin >> s;
    vector<int> a(s);
    for (auto& x : a) cin >> x;
    unordered_set<int> b(a.begin(), a.end());
    for (int i = a.front(); i <= a.back(); ++i) {
      if (!b.contains(i)) {
        for (auto& x : a) {
          adj[i][x] = true;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      if (adj[i][j]) e[i].push_back(j);
    }
  }
  TopoSort();
  cout << ans << endl;
  return 0;
}
