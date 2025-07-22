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

#define INF 0x3f3f3f3f
#define MAXN 200010

struct P {
  int x, y;
};
int n;
P a[MAXN];
int s1[MAXN], s2[MAXN];
int vis[MAXN];

int dis(int i, int j) { return abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y); }

void init() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;
  iota(s1 + 1, s1 + 1 + n, 1);
  iota(s2 + 1, s2 + 1 + n, 1);
  sort(s1 + 1, s1 + 1 + n, [](int i, int j) { return a[i].x + a[i].y < a[j].x + a[j].y; });
  sort(s2 + 1, s2 + 1 + n, [](int i, int j) { return a[i].x - a[i].y < a[j].x - a[j].y; });
  for (int i = 1; i <= n; ++i) vis[i] = 0;
}

void solve() {
  init();
  int i1 = 1, j1 = n, i2 = 1, j2 = n;
  int sum = 0;
  for (int i = 1; i <= n; ++i) cerr << s1[i] << " \n"[i == n];
  for (int i = 1; i <= n; ++i) cerr << s2[i] << " \n"[i == n];
  while (i1 <= j1 && i2 <= j2) {
    set<int> t;
    t.insert(s1[i1]), t.insert(s1[j1]), t.insert(s2[i2]), t.insert(s2[j2]);
    int d = 0, ii, jj;
    for (int u : t) {
      for (int v : t) {
        if (u < v && dis(u, v) > d) {
          d = dis(u, v);
          ii = u, jj = v;
        }
      }
    }
    vis[ii] = 1, vis[jj] = 1;
    cout << ii << " " << jj << "\n";
    sum += d;
    while (i1 <= j1 && vis[s1[i1]]) ++i1;
    while (i1 <= j1 && vis[s1[j1]]) --j1;
    while (i2 <= j2 && vis[s2[i2]]) ++i2;
    while (i2 <= j2 && vis[s2[j2]]) --j2;
  }
  cerr << sum << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
