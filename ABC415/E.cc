#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)(x).size()
#define MAXN 200010

using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;

void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }

istream& operator>>(istream& is, __int128& x) {
  int64_t y;
  is >> y;
  x = y;
  return is;
}

ostream& operator<<(ostream& os, const __int128& x) { return os << static_cast<int64_t>(x); }

int H, W;

void solve() {
  cin >> H >> W;
  vii a(H + 2, vi(W + 2));
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) cin >> a[i][j];
  }
  vi p(H + W + 1);
  vi q(H + W + 1);
  for (int i = 1; i <= H + W - 1; ++i) cin >> p[i];
  for (int i = 1; i <= H + W - 1; ++i) q[i] = q[i - 1] + p[i];
  vii dp(H + 2, vi(W + 2));
  vii lft(H + 2, vi(W + 2));
  dp[1][1] = max(0LL, p[1] - a[1][1]);
  lft[1][1] = max(0LL, a[1][1] - p[1]);
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) {
      if (i == 1 && j == 1) continue;
      int x = dp[i - 1][j] + max(0LL, p[i + j - 1] - (lft[i - 1][j] + a[i][j]));
      int y = dp[i][j - 1] + max(0LL, p[i + j - 1] - (lft[i][j - 1] + a[i][j]));
      int xx = max(0LL, lft[i - 1][j] + a[i][j] - p[i + j - 1]);
      int yy = max(0LL, lft[i][j - 1] + a[i][j] - p[i + j - 1]);
      // cerr << format("{} {} {} {} {} {}\n", i, j, x, y, xx, yy);
      if (i == 1) {
        dp[i][j] = y;
        lft[i][j] = yy;
      } else if (j == 1) {
        dp[i][j] = x;
        lft[i][j] = xx;
      } else if (x < y || (x == y && xx > yy)) {
        dp[i][j] = x;
        lft[i][j] = xx;
      } else {
        dp[i][j] = y;
        lft[i][j] = yy;
      }
    }
  }
  // for (int i = 1; i <= H; ++i) {
  //   for (int j = 1; j <= W; ++j) {
  //     cerr << format("[{} {}] ", dp[i][j], lft[i][j]);
  //   }
  //   cerr << "\n";
  // }
  cout << dp[H][W] << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
