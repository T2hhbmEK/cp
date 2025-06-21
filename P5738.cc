#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int main() {
  int n, m;
  double ans = -inf;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int mi = inf, ma = -inf, sum = 0;
    for (int j = 1, a; j <= m; j++) {
      cin >> a;
      mi = min(mi, a);
      ma = max(ma, a);
      sum += a;
    }
    ans = max(ans, 1.0 * (sum - mi - ma) / (m - 2));
  }
  cout << fixed << setprecision(2) << ans << endl;
  return 0;
}
