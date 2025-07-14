#include <bits/stdc++.h>
#define endl '\n'
#define sz(x) (int)(x).size()
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
void Yes() { cout << "Yes" << endl; }
void No() { cout << "No" << endl; }
void Ans(int x) { cout << x << endl; }
void solve() {
  int n, m, ans = numeric_limits<int>::max();
  cin >> n >> m;
  map<int, set<int>> e;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].insert(v), e[v].insert(u);
  }
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  do {
    {  // 1 loop
      int sum = 0;
      for (int i = 0; i < n; ++i) {
        if (!e[a[i]].contains(a[(i + 1) % n])) sum += 1;
      }
      sum += m - (n - sum);
      ans = min(ans, sum);
      // for (int i = 0; i < n; ++i) cerr << a[i];
      // cerr << endl;
      // cerr << sum << endl;
    }
    for (int k = 3; k <= n - 3; ++k) {
      int sum = 0;
      for (int i = 0; i < k; ++i) {
        if (!e[a[i]].contains(a[(i + 1) % k])) sum += 1;
      }
      for (int i = 0; i < n - k; ++i) {
        if (!e[a[i + k]].contains(a[(i + 1) % (n - k) + k])) sum += 1;
      }
      sum += m - (n - sum);
      ans = min(ans, sum);
    }
  } while (next_permutation(a.begin(), a.end()));
  return Ans(ans);
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
