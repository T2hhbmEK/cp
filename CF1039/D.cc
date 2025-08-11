#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)(x).size()
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using pq = priority_queue<int, vi, greater<>>;

constexpr int INF = numeric_limits<int>::max();
constexpr int MAXN = 2e5 + 10;
constexpr int MOD = 998244353;

int qpow(int a, int b) {
  int ans = 1;
  a = (a % MOD + MOD) % MOD;
  for (; b; b >>= 1) {
    if (b & 1) ans = (a * ans) % MOD;
    a = (a * a) % MOD;
  }
  return ans;
}

int inv(int x) { return qpow(x, MOD - 2); }

struct T {
  int l, r, p, q;
};
int n, m;
T a[MAXN];
int f[MAXN];
vector<int> mpL[MAXN];
vector<int> mpR[MAXN];
int vis[MAXN];
int pre[MAXN];

void solve() {  //
  cin >> n >> m;
  for (int i = 1, l, r, p, q; i <= n; ++i) {
    cin >> l >> r >> p >> q;
    a[i] = {.l = l, .r = r, .p = p, .q = q};
    mpL[l].push_back(i);
    mpR[r].push_back(i);
  }
  pre[0] = 1;
  for (int i = 1; i <= m; ++i) {
    pre[i] = pre[i - 1];
    for (int j : mpL[i]) {
      auto [l, r, p, q] = a[j];
      // cerr << format("i={} lrpq={} {} {} {}\n", i, l, r, p, q);
      pre[i] *= (q - p) * inv(q) % MOD;
      pre[i] %= MOD;
    }
  }
  f[0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j : mpR[i]) {
      auto [l, r, p, q] = a[j];
      int pp = pre[r] * inv(pre[l - 1]) % MOD;
      pp *= q * inv(q - p) % MOD;
      pp %= MOD;
      pp *= f[l - 1] * p % MOD * inv(q) % MOD;
      pp %= MOD;
      f[r] += pp;
      f[r] %= MOD;
    }
  }
  // for (int i = 1; i <= m; ++i) cerr << pre[i] << " \n"[i == m];
  // for (int i = 1; i <= m; ++i) cerr << f[i] << " \n"[i == m];
  cout << f[m] << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
