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
#define int long long
#define sz(x) (int)(x).size()
#define MAXN 8000010
using namespace std;
int n, m, q, u, v, t;
int a[MAXN];
queue<int> qs[3];
int getfront(const queue<int>& qq) {
  return qq.empty() ? numeric_limits<int>::min() : qq.front();
}
int popmax() {
  auto* qq = max_element(qs, qs + 3, [](const auto& ii, const auto& jj) {
    return getfront(ii) < getfront(jj);
  });
  int x = qq->front();
  qq->pop();
  return x;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> m >> q >> u >> v >> t;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + 1 + n, greater<>());
  for (int i = 1; i <= n; ++i) qs[0].push(a[i]);
  for (int i = 1, of = 0; i <= m; ++i, of += q) {
    int x = popmax();
    x += of;
    if (i % t == 0) print("{} ", x);
    int x1 = x * u / v;
    int x2 = x - x1;
    x1 -= of + q;
    x2 -= of + q;
    qs[1].push(x1), qs[2].push(x2);
  }
  println("");
  for (int i = 1, of = q * m; i <= n + m; ++i) {
    int x = popmax() + of;
    if (i % t == 0) print("{} ", x);
  }
  println("");
  return 0;
}
