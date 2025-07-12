#include <bits/stdc++.h>
#if __cplusplus > 202002L
#define eprint(...) print(stderr, __VA_ARGS__)
#define eprintln(...) println(stderr, __VA_ARGS__)
#else
#define eprint(...) void(cerr << format(__VA_ARGS__))
#define eprintln(...) void(cerr << format(__VA_ARGS__) << '\n')
#define print(...) void(cout << format(__VA_ARGS__))
#define println(...) void(cout << format(__VA_ARGS__) << '\n')
#endif
#define sz(x) (int)(x).size()
#define int long long
#define INF 0x7f7f7f7fLL
#define F first
#define S second
#define MAXN 300010
using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
int n, m;
pii a[MAXN];
tiii rli[MAXN];
pii yx[MAXN * 2];
int tot;
int ans;
int t[MAXN];
constexpr int lowbit(int x) { return x & -x; }
void add(int x, int k) {
  while (x <= n) {
    t[x] += k;
    x += lowbit(x);
  }
}
int query(int x) {
  int sum = 0;
  while (x > 0) {
    sum += t[x];
    x -= lowbit(x);
  }
  return sum;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i].F, a[i].S = i;
  for (int j = 1; j <= m; ++j) {
    auto &[r, l, i] = rli[j];
    cin >> l >> r;
    i = j;
  }
  sort(a + 1, a + 1 + n);
  sort(rli + 1, rli + 1 + m);
  a[0].F = -INF, a[n + 1].F = INF;
  for (int i = 1; i <= n; ++i) {
    int d = min(a[i + 1].F - a[i].F, a[i].F - a[i - 1].F);
    for (int j : {i - 1, i + 1}) {
      if (j >= 1 && j <= n && abs(a[i].F - a[j].F) == d) {
        int x = a[i].S, y = a[j].S;
        if (x > y) swap(x, y);
        yx[++tot] = {y, x};
      }
    }
  }
  sort(yx + 1, yx + 1 + tot);
  eprintln("{}", tot);
  for (int k = 1, j = 1; k <= m; ++k) {
    auto [r, l, i] = rli[k];
    while (j <= tot && yx[j].F <= r) add(yx[j++].S, 1);
    ans += i * ((j - 1) - query(l - 1));
  }
  println("{}", ans);
  return 0;
}
