#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define MAXN 1000010

void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }

int n;
string s;
int dp[MAXN];

void solve() {
  cin >> n >> s;
  dp[0] = 1;
  for (int i = 1; i <= (1 << n) - 1; ++i) {
    dp[i] = 0;
    if (s[i - 1] == '1') continue;
    for (int x = i; x; x = x ^ (x & -x)) {
      int j = x & -x;
      if (i & j && dp[i ^ j]) {
        // cerr << format("{:08b} -> {:08b}\n", i ^ j, i);
        dp[i] = 1;
        break;
      }
    }
  }
  return dp[(1 << n) - 1] ? Yes() : No();
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
