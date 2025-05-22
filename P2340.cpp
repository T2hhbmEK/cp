#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 410
#define maxv 1'000'010
using namespace std;

int n, s[maxn], f[maxn], ans;
unordered_map<int, int> dp[2];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i] >> f[i];
  dp[0][0] = 0;
  for (int i = 1, ib = 1; i <= n; i++, ib ^= 1) {
    dp[ib] = dp[ib ^ 1];
    for (auto &p : dp[ib ^ 1]) {
      int j = p.first;
      int k = p.second;
      if (dp[ib].find(j + s[i]) == dp[ib].end()) {
        dp[ib][j + s[i]] = -inf;
      }
      dp[ib][j + s[i]] = max(dp[ib][j + s[i]], k + f[i]);
    }
  }
  for (auto &p : dp[n & 1]) {
    int j = p.first;
    int k = p.second;
    if (j >= 0 && k >= 0) {
      ans = max(ans, j + k);
    }
  }
  cout << ans << endl;
  return 0;
}
