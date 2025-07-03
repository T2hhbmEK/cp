#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct DSU {
  unordered_map<int, int> fa_;
  int& fa(int u) { return fa_.contains(u) ? fa_[u] : fa_[u] = u; }
  int find(int u) { return fa(u) == u ? u : fa(u) = find(fa(u)); }
  void unite(int u, int v) {
    u = find(u), v = find(v);
    fa(u) = v;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  DSU dsu;
  vector<tuple<int, int, string>> a(m);
  for (auto& [u, v, s] : a) cin >> u >> v >> s, ++v;
  int ans = 0;
  unordered_set<int> ax;
  for (auto& [u, v, s] : a) {
    if (s == "odd") {
      dsu.unite(u, -v);
      dsu.unite(-u, v);
    } else {
      dsu.unite(u, v);
      dsu.unite(-u, -v);
    }
    // cerr << u << " " << v << " " << s << " " << dsu.find(u) << " "
    //      << dsu.find(-u) << endl;
    ax.insert(u), ax.insert(v);
    if (dsu.find(u) == dsu.find(-u)) break;
    ++ans;
  }
  cout << ans << endl;
  return 0;
}
