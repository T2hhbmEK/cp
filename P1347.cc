#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define maxn 32
using namespace std;
int n, m;
unordered_map<char, vector<int>> e;
enum Result { SORTED, INCONSISTENCY, PENDING };
string sorted;
Result TopoSort() {
  unordered_map<char, int> din, dout;
  for (auto& [u, vs] : e) {
    for (auto& v : vs) ++din[v], ++dout[u];
  }
  queue<int> q;
  for (char u = 'A'; u < 'A' + n; ++u) {
    // cout << u << " " << din[u] << " " << dout[u] << endl;
    if (din[u] == 0) q.push(u);
  }
  if (q.empty()) return Result::INCONSISTENCY;
  Result ans = Result::SORTED;
  unordered_set<char> vis;
  sorted = "";
  while (!q.empty()) {
    if (q.size() != 1) ans = Result::PENDING;
    int u = q.front();
    vis.insert(u);
    sorted += u;
    q.pop();
    for (auto& v : e[u]) {
      if (vis.contains(v)) return Result::INCONSISTENCY;
      if (--din[v] == 0) q.push(v);
    }
  }
  if ((int)sorted.size() != n) return Result::INCONSISTENCY;
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    char u, op, v;
    cin >> u >> op >> v;
    e[u].push_back(v);
    auto res = TopoSort();
    if (res == Result::SORTED) {
      cout << "Sorted sequence determined after " << i
           << " relations: " << sorted << "." << endl;
      return 0;
    } else if (res == Result::INCONSISTENCY) {
      cout << "Inconsistency found after " << i << " relations." << endl;
      return 0;
    }
  }
  cout << "Sorted sequence cannot be determined." << endl;
  return 0;
}
