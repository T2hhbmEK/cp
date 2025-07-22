#include <bits/stdc++.h>
using namespace std;
// clang-format off
#define int long long
#define sz(x) (int)(x).size()
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
istream& operator>>(istream& is, __int128& x) { int64_t y; return is >> y, x = y, is; }
ostream& operator<<(ostream& os, const __int128& x) { return os << static_cast<int64_t>(x); }
void Yes() { cout << "Yes\n"; } void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; } void NO() { cout << "NO\n"; }
void Ans(int x) { cout << x << "\n"; }
// clang-format on

#define MAXN 200010

int n;

void solve() {
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b > d) {  // move 1s, move all 0s
      ans += a + b - d;
    } else {  // don't move 1s
      if (a > c) {
        ans += a - c;
      }
    }
  }
  return Ans(ans);
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
