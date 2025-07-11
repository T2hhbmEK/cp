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
constexpr int lowbit(int x) { return x & -x; }
int n, m;
int a[MAXN];
int t[MAXN];
void init() {
  for (int i = 1; i <= n; ++i) {
    t[i] += a[i];
    int j = i + lowbit(i);
    if (j <= n) t[j] += t[i];
  }
}
void add(int x, int k) {
  a[x] += k;
  while (x <= n) {
    t[x] += k;
    x += lowbit(x);
  }
}
void add(int x, int y, int k) {
  add(x, k);
  if (y + 1 <= n) add(y + 1, -k);
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
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = n; i >= 1; --i) a[i] -= a[i - 1];
  init();
  while (m--) {
    int op, x, y, k;
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> k;
      add(x, y, k);
    } else {
      cin >> x;
      println("{}", query(x));
    }
  }
  return 0;
}
