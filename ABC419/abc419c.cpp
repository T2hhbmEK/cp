#include <bits/stdc++.h>
using namespace std;

// #define int __int128
#define int long long
#define endl '\n'
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
constexpr int MAXN = 2e5 + 10;
constexpr int MOD = 998244353;

void solve() {  //
  int n;
  cin >> n;
  vi xs(n), ys(n);
  for (int i = 0; i < n; ++i) cin >> xs[i] >> ys[i];
  int xmax = *max_element(xs.begin(), xs.end());
  int xmin = *min_element(xs.begin(), xs.end());
  int ymax = *max_element(ys.begin(), ys.end());
  int ymin = *min_element(ys.begin(), ys.end());
  int dx = xmax - xmin;
  int dy = ymax - ymin;
  int d = max(dx, dy);
  int ans = (d + 1) / 2;
  ans = max((int)0, ans);
  cout << ans << endl;
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}

istream& operator>>(istream& is, __int128& x) {
  bool neg = false;
  char ch = 0;
  x = 0;
  while (!isdigit(ch)) neg ^= ch == '-', ch = is.get();
  while (isdigit(ch)) x = (x << 3) + (x << 1) - (ch & 0xF), ch = is.get();
  if (!neg) x = -x;
  return is;
}

ostream& operator<<(ostream& os, __int128 x) {
  static char s[40];
  signed n = 0;
  if (x == 0) return os << 0;
  x = x < 0 ? (os << '-', x) : -x;
  while (x) s[n++] = '0' - x % 10, x /= 10;
  while (n) os.put(s[--n]);
  return os;
}
