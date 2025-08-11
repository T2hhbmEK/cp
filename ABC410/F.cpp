#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using pq = priority_queue<int, vi, greater<>>;
istream& operator>>(istream& is, __int128& x);
ostream& operator<<(ostream& os, __int128 x);
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }

constexpr int INF = numeric_limits<int>::max();
constexpr int MAXN = 3e5 + 10;
constexpr int MOD = 998244353;

int n, m;
vii a;
long long ans;

void transpose() {
  swap(n, m);
  vii b(n + 2, vi(m + 2));
  swap(a, b);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) a[i][j] = b[j][i];
  }
}

void solve() {  //
  cin >> n >> m;
  ans = 0;
  a = vii(n + 2, vi(m + 2));
  string s;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    for (int j = 1; j <= m; ++j) a[i][j] = s[j - 1] == '#' ? 1 : -1;
  }
  if (n > m) transpose();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }
  vi b(m + 2);
  unordered_map<int, int> cnt;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      cnt.clear();
      cnt[0] = 1;
      for (int k = 1; k <= m; ++k) {
        b[i] = a[j][k] - a[i - 1][k];
        ans += cnt[b[i]];
        cnt[b[i]] += 1;
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
