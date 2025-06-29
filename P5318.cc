#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int n, m, x, y;
unordered_map<int, set<int>> e;
unordered_set<int> vis;
void dfs(int u) {
  if (vis.contains(u)) return;
  cout << u << ' ';
  vis.insert(u);
  for (auto& v : e[u]) dfs(v);
}
queue<int> q;
void bfs(int u) {
  q.push(u);
  vis.insert(u);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    cout << u << ' ';
    for (auto& v : e[u]) {
      if (!vis.contains(v)) {
        q.push(v);
        vis.insert(v);
      }
    }
  }
}
int main() {
  cin >> n >> m;
  while (m--) {
    cin >> x >> y;
    e[x].insert(y);
  }
  dfs(1), cout << endl;
  vis.clear(), bfs(1), cout << endl;
  return 0;
}
