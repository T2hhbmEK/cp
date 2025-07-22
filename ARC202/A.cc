#include <bits/stdc++.h>
using namespace std;
// clang-format off
#define int long long
#define sz(x) (int)(x).size()
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using pq = priority_queue<int, vi, greater<>>;
using pqii = priority_queue<pii, vector<pii>, greater<>>;
istream& operator>>(istream& is, __int128& x) { int64_t y; return is >> y, x = y, is; }
ostream& operator<<(ostream& os, const __int128& x) { return os << static_cast<int64_t>(x); }
void Yes() { cout << "Yes\n"; } void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; } void NO() { cout << "NO\n"; }
void Ans(int x) { cout << x << "\n"; }
// clang-format on

constexpr int INF = numeric_limits<int>::max();
constexpr int MAXN = 2e5 + 10;

struct Solution {
  struct Node {
    int x, i, pre, nex;
  };
  int n, ans = 0;
  vector<Node> a;
  set<pii> s;
  Solution() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1, x; i <= n; ++i) {
      cin >> x;
      a[i] = {.x = x, .i = i, .pre = i - 1, .nex = i + 1};
      s.insert({x, i});
    }
    a[1].pre = 0, a[n].nex = 0;
    a[0].nex = 1, a[0].pre = n;
  }
  void prt() {
    // for (int i = 0; i <= n; ++i) {
    //   cerr << format("[{} {} {} {}] ", a[i].x, a[i].i, a[i].pre, a[i].nex);
    //   if (i == n) cerr << "\n";
    // }
    for (int i = a[0].nex; i; i = a[i].nex) cerr << a[i].x << " \n"[a[i].nex == 0];
  }
  void solve() {
    prt();
    while (sz(s) > 1) {
      auto [x, i] = *s.begin();
      s.erase(s.begin());
      assert(x == a[i].x);
      int j = i;
      if (a[i].pre == 0) {
        j = a[i].nex;
      } else if (a[i].nex == 0) {
        j = a[i].pre;
      } else {
        j = a[a[i].pre].x <= a[a[i].nex].x ? a[i].pre : a[i].nex;
      }
      // cerr << format("a[{}]={}\n", j, a[j].x);
      assert(s.find({a[j].x, j}) != s.end());
      s.erase(s.find({a[j].x, j}));
      ans += a[j].x - a[i].x;
      a[j].x += 1;
      s.insert({a[j].x, j});
      if (j < i) {
        a[a[i].nex].pre = j;
        a[j].nex = a[i].nex;
      } else {
        a[a[i].pre].nex = j;
        a[j].pre = a[i].pre;
      }
      prt();
    }
    return Ans(ans);
  }
};

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) Solution().solve();
  return 0;
}
