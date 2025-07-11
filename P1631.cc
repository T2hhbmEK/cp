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
using pii = pair<int, int>;
int n;
int a[MAXN], b[MAXN];
int js[MAXN];
priority_queue<pii, vector<pii>, greater<>> q;
signed main() {  // O(nlognlogn)
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i], js[i] = 1;
  for (int i = 1; i <= n; ++i) q.emplace(a[i] + b[js[i]++], i);
  for (int k = 1; k <= n; ++k) {
    const auto [x, i] = q.top();
    q.pop();
    print("{} ", x);
    if (js[i] <= n) q.emplace(a[i] + b[js[i]++], i);
  }
  println("");
  return 0;
}
