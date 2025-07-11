#include <bits/stdc++.h>
#if __cplusplus > 202002L
#define eprint(...) print(stderr, __VA_ARGS__)
#define eprintln(...) println(stderr, __VA_ARGS__)
#else
#define eprint(...) cerr << format(__VA_ARGS__)
#define eprintln(...) cerr << format(__VA_ARGS__) << '\n'
#define print(...) cout << format(__VA_ARGS__)
#define println(...) cout << format(__VA_ARGS__) << '\n'
#endif
#define sz(x) (int)(x).size()
#define MAXN 200010
using namespace std;
using pii = pair<int, int>;
int n;
string s;
int a[MAXN], erased[MAXN];
list<int> b;
// using item = tuple<int, int, int, list<int>::iterator>;
struct item {
  int d, i, j;
  list<int>::iterator it;
  bool operator>(const item& other) const {
    if (d != other.d) return d > other.d;
    return i > other.i;
  }
};
priority_queue<item, vector<item>, greater<>> q;
vector<pii> ans;
void solve() {
  for (int i = 0; i < n; ++i) b.push_back(i);
  for (auto it = b.begin(); next(it) != b.end(); it = next(it)) {
    auto jt = next(it);
    int i = *it, j = *(jt);
    if (s[i] != s[j]) {
      q.emplace(abs(a[i] - a[j]), i, j, it);
    }
  }
  while (!q.empty()) {
    auto [d, i, j, it] = q.top();
    q.pop();
    if (erased[i] || erased[j]) continue;
    erased[i] = erased[j] = 1;
    b.erase(next(it));
    it = prev(b.erase(it));
    auto jt = next(it);
    if (it != b.end() && jt != b.end() && s[*it] != s[*jt]) {
      q.emplace(abs(a[*it] - a[*jt]), *it, *jt, it);
    }
    ans.emplace_back(i, j);
  }
  println("{}", ans.size());
  for (auto& [i, j] : ans) println("{} {}", i + 1, j + 1);
}
void test() {
  srand(time(nullptr));
  n = rand() % 10 + 1;
  for (int i = 0; i < n; ++i) s += "BG"[rand() % 2];
  for (int i = 0; i < n; ++i) a[i] = rand() % n + 1;
  eprintln("{}\n{}", n, s);
  for (int i = 0; i < n; ++i) eprint("{} ", a[i]);
  eprintln("");
  solve();
  exit(0);
}
signed main() {
  // test();
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; ++i) cin >> a[i];
  solve();
  return 0;
}
