#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)(x).size()
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using pq = priority_queue<int, vi, greater<>>;

void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }

constexpr int INF = numeric_limits<int>::max();
constexpr int MAXN = 1e5 + 10;
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

int n, m;
int a[MAXN][10];
map<int, vector<pii>> mp;
int qinv;
int b[MAXN * 10];

void init() {
  int inv6 = inv(6);
  qinv = 1;
  for (int i = 1; i <= n; ++i) {
    qinv *= inv6;
    qinv %= MOD;
  }
}

void solve() {  //
  cin >> n;
  init();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      cin >> a[i][j];
    }
    sort(a[i] + 1, a[i] + 1 + 6);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      mp[a[i][j]].emplace_back(i, j);
    }
  }
  m = sz(mp);
  for (int i = 0; auto& [k, v] : mp) b[++i] = k;
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
