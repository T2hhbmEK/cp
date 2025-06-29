#include <iostream>
#include <numeric>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
struct DSU {
  vector<int> pa, sz;
  DSU(int n) : pa(n + 1), sz(n + 1, 1) { iota(pa.begin(), pa.end(), 0); }
  int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
  void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    pa[x] = y;
    sz[y] += sz[x];
  }
};
bool isPrime(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return x >= 2;
}
int main() {
  int a, b, p;
  cin >> a >> b >> p;
  DSU dsu(b);
  for (int i = p; i <= b; ++i) {
    if (isPrime(i)) {
      int x = (a + i - 1) / i * i;
      for (int j = x + i; j <= b; j += i) {
        dsu.unite(x, j);
      }
    }
  }
  unordered_set<int> s;
  for (int i = a; i <= b; ++i) {
    s.insert(dsu.find(i));
  }
  cout << s.size() << endl;
  return 0;
}
