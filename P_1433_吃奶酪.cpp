#include <bits/stdc++.h>
#define inf 1000000007
#define maxn 16
using namespace std;

namespace sol {

int n;
double x[maxn], y[maxn];
double dp[maxn][1 << maxn], ans = inf;

inline int mask(int i) {
  return 1 << (i - 1);
}

inline double dis(int i, int j = 0) {
  return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

double f(int i, int j) {
  if (dp[i][j] >= 0) return dp[i][j];
  dp[i][j] = inf;
  for (int k = 1; k <= n; k++) {
    if (j & mask(k) && i != k) {
      dp[i][j] = min(dp[i][j], f(k, j ^ mask(i)) + dis(i, k));
    }
  }
  // cerr << i << " " << bitset<4>(j) << " " << dp[i][j] << endl;
  return dp[i][j];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < mask(n + 1); j++) {
      dp[i][j] = -1;
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    dp[i][mask(i)] = dis(i);
  }
  for (int i = 1; i <= n; i++) {
    ans = min(ans, f(i, mask(n + 1) - 1));
  }
  cout << fixed << setprecision(2) << ans << endl;
  return 0;
}

}  // namespace sol

int main() {
  return sol::main();
}
