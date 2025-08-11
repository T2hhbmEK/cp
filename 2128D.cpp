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

constexpr int INF = 0x3f3f3f3f;
constexpr int MAXN = 5e5 + 10;
constexpr int MOD = 998244353;

int n;
int a[MAXN];

int f1[MAXN];  // f1[i] LSD ends at i
int f2[MAXN];  // f2[i]=j LSD ends at j > LSD ends at i

int g1[MAXN];  // g1[i] sum r=i
// int g2[MAXN];  // g2[i] sum [l,r] in [1,i]
int ans;

void bf() {
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      int sum = 1, mx = 1;
      for (int k = i + 1; k <= j; ++k) {
        if (a[k] < a[k - 1]) {
          sum += 1;
        } else {
          sum = 1;
        }
        mx = max(mx, sum);
      }
      ans += mx;
    }
  }
}

void solve() {  //
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    if (a[i] < a[i - 1]) {
      f1[i] = f1[i - 1] + 1;
    } else {
      f1[i] = 1;
    }
    f2[i] = f1[f2[i - 1]] > f1[i] ? f2[i - 1] : i;
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] > a[i - 1]) {
      g1[i] = g1[i - 1] + 1;
    } else {
      if (f2[i] == i) {
        g1[i] = (1 + f1[i]) * f1[i] / 2 + f1[i] * (i - f1[i]);
      } else {
        cerr << format("i={}, f2[i]={}, f1[i]={}\n", i, f2[i], f1[i]);
        g1[i] = g1[i - 1] + (i - (f2[i] - f1[i] + 2));
      }
    }
  }
  for (int i = 1; i <= n; ++i) cerr << f1[i] << " \n"[i == n];
  for (int i = 1; i <= n; ++i) cerr << f2[i] << " \n"[i == n];
  for (int i = 1; i <= n; ++i) cerr << g1[i] << " \n"[i == n];
  cerr << '\n';
  bf();
  cout << ans << '\n';
  ans = 0;
  for (int i = 1; i <= n; ++i) ans += g1[i];
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
