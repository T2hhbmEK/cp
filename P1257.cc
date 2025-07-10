#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
constexpr int sq(int x) { return x * x; }
constexpr int sq_dis(const pii &a, const pii &b) {
  int dx = a.first - b.first, dy = a.second - b.second;
  return (dx * dx) + (dy * dy);
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pii> a(n);
  for (auto &[x, y] : a) cin >> x >> y;
  ranges::sort(a);
  int ans = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n && sq(a[j].first - a[i].first) < ans; ++j) {
      ans = min(ans, sq_dis(a[i], a[j]));
    }
  }
  cout << fixed << setprecision(4) << sqrt(ans) << '\n';
  return 0;
}
