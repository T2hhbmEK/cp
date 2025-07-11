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
#define MAXN 10010
using namespace std;
int n, m;
vector<tuple<int, int, int>> p;
priority_queue<int> q;
stack<int> s;
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0, a, b, c; i < n; ++i) {
    cin >> a >> b >> c;
    p.emplace_back(a, b, c);
  }
  sort(p.begin(), p.end());
  for (const auto& [a, b, c] : p) {
    const auto f = [&](int x) { return a * x * x + b * x + c; };
    int j = 1;
    while (sz(q) < m) q.push(f(j++));  // excuted only when i == 1
    while (q.top() > f(j)) q.push(f(j++)), q.pop();
  }
  assert(sz(q) == m);
  while (!q.empty()) s.push(q.top()), q.pop();
  while (!s.empty()) print("{} ", s.top()), s.pop();
  println("");
  return 0;
}
