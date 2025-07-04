#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  unordered_set<int> s;
  int ans = 0;
  for (int i = 0, j = 0; j < n; ++j) {
    while (s.find(a[j]) != s.end()) s.erase(a[i++]);
    s.insert(a[j]);
    assert(j - i + 1 == (int)s.size());
    ans = max(ans, j - i + 1);
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
