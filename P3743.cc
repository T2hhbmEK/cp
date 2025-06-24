#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
constexpr double EPS = 1e-6;
double bs(double lo, double hi, function<bool(double)> chk) {
  while (lo + EPS < hi) {
    double mid = lo + (hi - lo) / 2;
    if (chk(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return lo;
}

int main() {
  int n, p;
  cin >> n >> p;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  long long sa = accumulate(a.begin(), a.end(), 0LL);
  long long sb = accumulate(b.begin(), b.end(), 0LL);
  if (sa <= p) {
    cout << -1 << endl;
    return 0;
  }
  double ans = bs(0.0, (double)sb / (sa - p), [&](double k) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
      sum += max(0.0, k * a[i] - b[i]);
    }
    return sum <= p * k;
  });
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
