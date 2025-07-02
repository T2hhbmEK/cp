#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  i64 n, m, s;
  cin >> n >> m >> s;
  vector<i64> w(n + 1, 0), v(n + 1, 0), l(m + 1, 0), r(m + 1, 0);
  for (i64 i = 1; i <= n; ++i) cin >> w[i] >> v[i];
  for (i64 i = 1; i <= m; ++i) cin >> l[i] >> r[i];
  i64 lo = *min_element(w.begin() + 1, w.end());
  i64 hi = *max_element(w.begin() + 1, w.end());
  i64 ans = 0;
  while (lo <= hi) {
    i64 mi = lo + (hi - lo) / 2;
    vector<i64> w_(w), v_(v);
    for (i64 i = 1; i <= n; ++i) {
      w_[i] = w_[i] >= mi;
      v_[i] *= w_[i];
      w_[i] += w_[i - 1];
      v_[i] += v_[i - 1];
    }
    i64 y = 0;
    for (i64 i = 1; i <= m; ++i) {
      y += (w_[r[i]] - w_[l[i] - 1]) * (v_[r[i]] - v_[l[i] - 1]);
    }
    if (abs(s - y) < abs(s - ans)) ans = y;
    if (y == s) {
      break;
    } else if (y > s) {
      lo = mi + 1;
    } else if (y < s) {
      hi = mi - 1;
    }
  }
  cout << abs(s - ans) << endl;
  return 0;
}
