#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vi = vector<int>;
int bs(int lo, int hi, function<bool(int)> chk) {
  while (lo < hi) {
    int mi = (lo + hi + 1) >> 1;
    if (chk(mi)) {
      lo = mi;
    } else {
      hi = mi - 1;
    }
  }
  return lo;
}
int main() {
  int n, m;
  cin >> n >> m;
  vi a(n);
  for (auto& x : a) cin >> x;
  int lo = 0, hi = *max_element(a.begin(), a.end());
  int ans = bs(lo, hi, [&](int h) {
    ll sum = 0;
    for (auto x : a) sum += max(0, x - h);
    return sum >= m;
  });
  cout << ans << endl;
  return 0;
}
