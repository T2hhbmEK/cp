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
priority_queue<int> qL;
priority_queue<int, vector<int>, greater<>> qR;
void add(int x) { qL.push(x), qR.push(qL.top()), qL.pop(); }
int get() {
  static int i = 0;
  i += 1;
  while (sz(qL) < i) qL.push(qR.top()), qR.pop();
  while (sz(qL) > i) qR.push(qL.top()), qL.pop();
  return qL.top();
}
int a[MAXN], u[MAXN];
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= m; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> u[i];
  for (int i = 1, j = 1; j <= n; ++j) {
    while (i <= u[j]) add(a[i++]);
    println("{}", get());
  }
  return 0;
}
