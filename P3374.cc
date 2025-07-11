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
#define MAXN 500010
using namespace std;
int n, m;
int a[MAXN];
int t[MAXN];
constexpr int lowbit(int x) { return x & -x; }
void add(int i, int x) {
  a[i] += x;
  while (i <= n) {
    t[i] += x;
    i += lowbit(i);
  }
}
int query(int i) {
  int sum = 0;
  while (i > 0) {
    sum += t[i];
    i -= lowbit(i);
  }
  return sum;
}
int query(int i, int j) { return query(j) - query(i - 1); }
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    t[i] += a[i];
    int j = i + lowbit(i);
    if (j <= n) t[j] += t[i];
  }
  while (m--) {
    int op, x, y, k;
    cin >> op;
    if (op == 1) {
      cin >> x >> k;
      add(x, k);
    } else {
      cin >> x >> y;
      println("{}", query(x, y));
    }
  }
  return 0;
}
