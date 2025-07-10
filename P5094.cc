#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Cow {
  int v, x;
};
int solve(vector<Cow>& a, int lo, int hi) {
  if (hi - lo <= 1) return 0;
  auto mi = lo + ((hi - lo) >> 1);
  int sum = solve(a, lo, mi) + solve(a, mi, hi);
  vector<int> pre(mi - lo + 1, 0);
  for (int i = 1; i <= mi - lo; ++i) pre[i] = pre[i - 1] + a[lo + i - 1].x;
  constexpr auto cmp = [](auto a, auto b) { return a.x < b.x; };
  for (int i = mi; i < hi; ++i) {
    int k = lower_bound(a.begin() + lo, a.begin() + mi, a[i], cmp) - a.begin();
    int n1 = k - lo, n2 = mi - lo;
    sum += a[i].v * (a[i].x * n1 - pre[n1]);
    sum += a[i].v * (pre[n2] - pre[n1] - a[i].x * (n2 - n1));
  }
  vector<Cow> t(hi - lo);
  merge(a.begin() + lo, a.begin() + mi, a.begin() + mi, a.begin() + hi,
        t.begin(), cmp);
  for (int i = lo; i < hi; ++i) a[i] = t[i - lo];
  return sum;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  vector<Cow> a(n);
  for (auto& [v, x] : a) cin >> v >> x;
  sort(a.begin(), a.end(), [](auto a, auto b) { return a.v < b.v; });
  int ans = solve(a, 0, n);
  cout << ans << '\n';
  return 0;
}
