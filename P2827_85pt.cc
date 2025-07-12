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
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> m >> q >> u >> v >> t;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  priority_queue<int> pq(a + 1, a + 1 + n);
  for (int i = 1, of = 0; i <= m; ++i, of += q) {
    int x = pq.top();
    pq.pop();
    x += of;
    if (i % t == 0) print("{} ", x);
    int x1 = x * u / v;
    int x2 = x - x1;
    x1 -= of + q;
    x2 -= of + q;
    pq.push(x1), pq.push(x2);
  }
  println("");
  for (int i = 1, of = q * m; !pq.empty(); ++i, pq.pop()) a[i] = pq.top() + of;
  for (int i = 1; i <= n + m; i += t) print("{} ", a[i]);
  println("");
  return 0;
}
