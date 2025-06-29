#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
using Factors = unordered_map<int, int>;
constexpr int inf = 0x3f3f3f3f;

Factors factorize(int n) {
  Factors a;
  for (int i = 2; i * i <= n; ++i) {
    while (n % i == 0) ++a[i], n /= i;
  }
  if (n > 1) ++a[n];
  return a;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m1, m2, ans = inf;
  cin >> n >> m1 >> m2;
  vector<int> s(n);
  for (auto& x : s) cin >> x;
  Factors fm = factorize(m1);
  for (auto& [k, v] : fm) v *= m2;
  for (auto& x : s) {
    int t = 0;
    Factors fx = factorize(x);
    for (auto& [k, _] : fm) {
      if (!fx.contains(k)) {
        t = -1;
        break;
      }
      t = max(t, (fm[k] - 1 + fx[k]) / fx[k]);
    }
    if (t >= 0) {
      ans = min(ans, t);
    }
  }
  if (ans == inf) ans = -1;
  cout << ans << endl;
  return 0;
}
