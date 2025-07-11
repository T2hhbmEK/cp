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
#define MAXN 100010
using namespace std;
int a[MAXN];
priority_queue<int> qL;
priority_queue<int, vector<int>, greater<>> qR;
void add(int x) { qL.push(x), qR.push(qL.top()), qL.pop(); }
int get() {
  while (sz(qL) < sz(qR)) qL.push(qR.top()), qR.pop();
  // eprintln("{} {}", sz(qL), sz(qR));
  return qL.top();
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    add(a[i]);
    if (i % 2 != 0) println("{}", get());
  }
  return 0;
}
