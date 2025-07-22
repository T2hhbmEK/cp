#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)(x).size()

using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;

// clang-format off
istream& operator>>(istream& is, __int128& x) { int64_t y; return is >> y, x = y, is; }
ostream& operator<<(ostream& os, const __int128& x) { return os << static_cast<int64_t>(x); }
void Yes() { cout << "Yes\n"; } void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; } void NO() { cout << "NO\n"; }
void Ans(int x) { cout << x << "\n"; }
// clang-format on

#define MAXN 200010

int n, m;

void solve() {
  cin >> n >> m;
  if (n == 1 || m == 1) return NO();
  return n >= 3 || m >= 3 ? YES() : NO();
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
