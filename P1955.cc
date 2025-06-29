#include <algorithm>
#include <iostream>
#include <numeric>
#include <tuple>
#include <unordered_map>
#include <vector>
#define maxn 200010
using namespace std;
namespace dsu {
int pa[maxn], h[maxn];
void reset(int n) {
  iota(pa + 1, pa + 1 + n, 1);
  fill(h + 1, h + 1 + n, 1);
}
int find(int x) { return pa[x] == x ? x : find(pa[x]); }
void unite(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (h[x] > h[y]) swap(x, y);
  pa[x] = y;
  h[y] = max(h[y], h[x] + 1);
}
}  // namespace dsu
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<tuple<int, int, int>> a(n);
    unordered_map<int, int> mp;
    int cnt = 0;
    for (auto& [i, j, e] : a) {
      cin >> i >> j >> e;
      if (mp.find(i) == mp.end()) mp[i] = ++cnt;
      if (mp.find(j) == mp.end()) mp[j] = ++cnt;
      i = mp[i], j = mp[j];
    }
    dsu::reset(cnt);
    for (auto& [i, j, e] : a) {
      if (e) dsu::unite(i, j);
    }
    bool flag = true;
    for (auto& [i, j, e] : a) {
      if (!e && dsu::find(i) == dsu::find(j)) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
