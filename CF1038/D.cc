#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
// clang-format off
#define int long long
#define sz(x) (int)(x).size()
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
istream& operator>>(istream& is, __int128& x) { int64_t y; return is >> y, x = y, is; }
ostream& operator<<(ostream& os, const __int128& x) { return os << static_cast<int64_t>(x); }
void Yes() { cout << "Yes\n"; } void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; } void NO() { cout << "NO\n"; }
void Ans(int x) { cout << x << "\n"; }
// clang-format on

#define INF 0x3f3f3f3f
#define MAXN 5010

int n, m;
vi e[MAXN];
int ans = INF, tot_wt = INF;
int dp[MAXN];

void dfs(int u, int t, int wt) {
  if (t >= dp[u]) return;
  dp[u] = t;
  if (u == n) {
    if (t <= ans) {
      ans = t;
      tot_wt = min(tot_wt, t);
    }
    return;
  }
  int d = sz(e[u]);
  for (int i = 0; i < d; ++i) {
    int v = e[u][i];
    int wtt = ((i - t) % d + d) % d;
    dfs(v, t + wtt + 1, wt + wtt);
  }
}

void dfs2(int u, int t, int wt) {
  if (t > ans) return;
  if (wt > tot_wt) return;
  if (u == n) {
    tot_wt = min(tot_wt, wt);
    return;
  }
  int d = sz(e[u]);
  for (int i = 0; i < d; ++i) {
    int v = e[u][i];
    int wtt = ((i - t) % d + d) % d;
    dfs2(v, t + wtt + 1, wt + wtt);
  }
}

void reset() {
  ans = INF, tot_wt = INF;
  for (int i = 1; i <= n; ++i) e[i].clear(), dp[i] = INF;
}

void solve() {
  cin >> n >> m;
  reset();
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v), e[v].push_back(u);
  }
  dfs(1, 0, 0);
  for (int i = 1; i <= n; ++i) dp[i] = INF;
  dfs2(1, 0, 0);
  cout << ans << " " << tot_wt << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
