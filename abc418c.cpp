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
  int n, q;
  cin >> n >> q;
  vi a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  vi presum(a);
  for (int i = 1; i < sz(presum); ++i) presum[i] += presum[i - 1];
  int amax = *max_element(a.begin(), a.end());
  while (q--) {
    int b;
    cin >> b;
    if (b > amax) {
      cout << -1 << endl;
    } else {
      int i = lower_bound(a.begin(), a.end(), b) - a.begin();
      int ans = i > 0 ? presum[i - 1] : 0;
      ans += (n - i) * (b - 1);
      cout << ans + 1 << endl;
    }
  }
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
