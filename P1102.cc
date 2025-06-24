#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ll n, c, ans = 0;
  cin >> n >> c;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  for (auto it = a.begin(); it != a.end(); it = next(it)) {
    ll b = *it + c;
    auto lo = lower_bound(next(it), a.end(), b);
    auto hi = upper_bound(next(it), a.end(), b);
    ans += distance(lo, hi);
  }
  cout << ans << endl;
  return 0;
}
