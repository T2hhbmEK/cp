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

pii calc_dir(const pii& u, const pii& v) {
  if (u.first > v.first) return calc_dir(v, u);
  pii d;
  d.first = v.first - u.first;
  d.second = v.second - u.second;
  if (d.first == 0 && d.second == 0) return d;
  if (d.first == 0) {
    d.second = 1;
    return d;
  }
  if (d.second == 0) {
    d.first = 1;
    return d;
  }
  int g = __gcd(d.first, abs(d.second));
  d.first /= g;
  d.second /= g;
  return d;
}

int calc_dis2(const pii& u, const pii& v) {
  int dx = u.first - v.first;
  int dy = u.second - v.second;
  return dx * dx + dy * dy;
}

void solve() {  //
  int n;
  cin >> n;
  vector<pii> a(n);
  for (auto& [x, y] : a) cin >> x >> y;
  map<pii, vector<pii>> mp;
  map<int, map<pii, int>> mp2;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      pii dr = calc_dir(a[i], a[j]);
      int d2 = calc_dis2(a[i], a[j]);
      mp[dr].emplace_back(i + 1, j + 1);
      mp2[d2][dr]++;
    }
  }
  int ans = 0;
  for (auto [k, v] : mp) {
    if (sz(v) >= 2) {
      ans += sz(v) * (sz(v) - 1) / 2;
    }
  }
  // cerr << ans << endl;
  int ans2 = 0;
  for (auto [d2, kv] : mp2) {
    for (auto [k, v] : kv) {
      // cerr << format("{}, ({},{}), {}\n", d2, k.first, k.second, v);
      if (v >= 2) {
        ans2 += v * (v - 1) / 2;
      }
    }
  }
  cout << ans - ans2 / 2 << endl;
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
