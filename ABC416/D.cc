#include <bits/stdc++.h>
using namespace std;

#define int long long
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
int a[MAXN], b[MAXN];
int ans;
void solve() {  //
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    a[i] %= m;
    b[i] %= m;
    ans += a[i] + b[i];
  }
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  int i = n, j = 1;
  while (i >= 1 && j <= n) {
    while (j <= n && a[i] + b[j] < m) ++j;
    if (j > n) break;
    ans -= m;
    ++j, --i;
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
