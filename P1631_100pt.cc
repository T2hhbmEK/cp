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
int n;
int a[MAXN], b[MAXN];
priority_queue<int> q;
stack<int> s;
signed main() {  // O(nlognlogn)
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  if (a[1] + b[n] > b[1] + a[n]) swap(a, b);
  for (int i = 1; i <= n; ++i) q.push(a[1] + b[i]);
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= n && a[i] + b[j] < q.top(); ++j) {
      // eprint("{} ", j);
      q.push(a[i] + b[j]);
      q.pop();
    }
    // eprintln("");
  }
  while (!q.empty()) s.push(q.top()), q.pop();
  while (!s.empty()) print("{} ", s.top()), s.pop();
  println("");
  return 0;
}
