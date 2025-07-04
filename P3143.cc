#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  vector<int> L(n), R(n);
  int ans = 0, mx = 0;
  for (int lo = 0, j = 0, hi = 0; j < n; ++j) {
    if (j > 0) {
      while (lo < j && a[lo] < a[j - 1] - k) ++lo;
    }
    mx = max(mx, j - lo);
    while (hi < n && a[hi] <= a[j] + k) ++hi;
    ans = max(ans, mx + hi - j);
  }
  cout << ans << endl;
  return 0;
}
