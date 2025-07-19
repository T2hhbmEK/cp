#include <bits/stdc++.h>
using namespace std;

#define int __int128
#define sz(x) (int)(x).size()
#define MAXN 200010

using pii = pair<int, int>;

void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }

istream& operator>>(istream& is, __int128& x) {
  int64_t y;
  is >> y;
  x = y;
  return is;
}

ostream& operator<<(ostream& os, const __int128& x) { return os << static_cast<int64_t>(x); }

struct P {
  int a, b;
};

bool cmp(const P& x, const P& y) {
  // if (x.a * y.b != y.a * x.b) return x.a * y.b < y.a * x.b;
  if (x.a - x.b != y.a - y.b) return x.a - x.b < y.a - y.b;
  return x.a < y.a;
}

int n, m, ans;
P s[MAXN];

void bf() {
  vector<int> p(m);
  iota(p.begin(), p.end(), 1);
  ans = 0;
  do {
    int sum = 0, nn = n;
    for (int i : p) {
      auto [a, b] = s[i];
      int x = max((nn - b) / (a - b), (int)0);
      nn -= (a - b) * x;
      sum += x;
    }
    ans = max(ans, sum);
    // if (ans == sum) {
    //   for (int i : p) cerr << format("[{} {}] ", s[i].a, s[i].b);
    //   cerr << sum << endl;
    // }
  } while (next_permutation(p.begin(), p.end()));
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    auto& [a, b] = s[i];
    cin >> a >> b;
  }
  sort(s + 1, s + 1 + m, cmp);
  // for (int i = 1; i <= m; ++i) cerr << format("[{} {}] ", s[i].a, s[i].b);
  // cerr << endl << endl;
  // bf();
  ans = 0;
  for (int i = 1; i <= m; ++i) {
    auto [a, b] = s[i];
    int x = (n - b) / (a - b);
    x = max((int)0, x);
    n -= (a - b) * x;
    ans += x;
    // cerr << format("{} {} {} {}\n", a, b, x, n);
  }
  cout << ans << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
