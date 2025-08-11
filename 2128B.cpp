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
constexpr int MAXN = 2e5 + 10;
constexpr int MOD = 998244353;

int n;
int p[MAXN];

void solve() {  //
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  int i = 1, j = n;
  string ans;
  while (i <= j) {
    int cnt = j - i + 1;
    if (cnt == 1) {
      ans += "L", i++;
    } else if (cnt == 2) {
      if (p[i] > p[j]) {
        ans += "RL", j--, i++;
      } else {
        ans += "LR", i++, j--;
      }
    } else if (cnt >= 3) {
      if (p[i] > p[j] && p[i] > p[i + 1]) {
        ans += "RLL";
      } else if (p[j] > p[i] && p[j] > p[i + 1]) {
        ans += "LRL";
      } else {
        ans += "LLR";
      }
      i += 2, j -= 1;
    }
  }
  // for (int i = 1, j = n; char c : ans) {
  //   if (c == 'L') cerr << p[i++];
  //   if (c == 'R') cerr << p[j--];
  // }
  // cerr << '\n';
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
