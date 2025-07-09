#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  {  // +1 -1
    ll cp = 0, cn = 0;
    for (auto& x : a) cp += x == a[0];
    if (cp == n) return true;
    for (auto& x : a) cn += x == -a[0];
    if (cp + cn == n && abs(cp - cn) <= 1) return true;
  }
  ranges::sort(a, {}, [](auto x) { return abs(x); });
  for (int i = 0; i < n - 1; ++i) {
    if (a[i + 1] * a[0] != a[1] * a[i]) return false;
  }
  return true;
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) cout << (solve() ? "Yes" : "No") << '\n';
  return 0;
}
