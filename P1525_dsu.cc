#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
struct T {
  int a, b, c;
};
namespace dsu {
constexpr int maxn = 40010;
int pa[maxn], sz[maxn];
void init() {
  iota(pa, pa + maxn, 0);
  fill(sz, sz + maxn, 1);
}
int find(int u) { return pa[u] == u ? u : pa[u] = find(pa[u]); }
void unite(int u, int v) {
  u = find(u), v = find(v);
  if (sz[u] > sz[v]) swap(u, v);
  pa[u] = v, sz[v] += sz[u];
}
};  // namespace dsu
int main() {
  dsu::init();
  int n, m;
  cin >> n >> m;
  vector<T> s(m);
  for (auto& x : s) cin >> x.a >> x.b >> x.c;
  sort(s.begin(), s.end(), [](T& x, T& y) { return x.c > y.c; });
  for (auto& x : s) {
    if (dsu::find(x.a) == dsu::find(x.b)) {
      cout << x.c << endl;
      return 0;
    }
    dsu::unite(x.a, x.b + n);
    dsu::unite(x.b, x.a + n);
  }
  cout << 0 << endl;
  return 0;
}
