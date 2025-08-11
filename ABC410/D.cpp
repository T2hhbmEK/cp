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
constexpr int MAXN = 1024;
constexpr int MOD = 998244353;

int n, m;
vpii e[MAXN];
int vis[MAXN][MAXN];
int ans = -1;

void dfs(int u, int d) {
  if (vis[u][d]) return;
  vis[u][d] = 1;
  for (auto [v, w] : e[u]) {
    dfs(v, d ^ w);
  }
}

void solve() {  //
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
  }
  dfs(1, 0);
  for (int i = 0; i < 1024; ++i) {
    if (vis[n][i]) {
      ans = i;
      break;
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
