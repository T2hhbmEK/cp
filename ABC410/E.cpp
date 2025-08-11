#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)(x).size()
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using vpii = vector<pii>;
using pq = priority_queue<int, vi, greater<>>;

void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }

constexpr int INF = numeric_limits<int>::max();
constexpr int MAXN = 6e3 + 10;
constexpr int MOD = 998244353;

int n, h, m;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];
// dp[i][j] maximum magic power left
// after defeat monster i with j health left
int ans;

void solve() {  //
  memset(dp, -1, sizeof(dp));
  cin >> n >> h >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  for (int j = 0; j <= h; ++j) dp[0][j] = m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= h; ++j) {
      dp[i][j] = max({
          dp[i - 1][j + a[i]],
          dp[i - 1][j] - b[i],
      });
      if (dp[i][j] >= 0) ans = i;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
