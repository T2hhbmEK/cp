#include <bits/stdc++.h>
#define int long long
#ifndef DEBUG
#define debug(...)
#define debugln(...)
#else
#define debug(...) cerr << format(__VA_ARGS__)
#define debugln(...) cerr << format(__VA_ARGS__) << '\n'
#endif
#define print(...) cout << format(__VA_ARGS__)
#define println(...) cout << format(__VA_ARGS__) << '\n'
#define MAXN 50
#define MAXM 2000000
using namespace std;
int n, m, a[MAXN], ans;
vector<int> sumL, sumR;
void dfs(int lo, int hi, int sum, auto& st) {
  if (sum > m) return;
  if (lo > hi) {
    st.push_back(sum);
    return;
  }
  dfs(lo + 1, hi, sum, st);
  dfs(lo + 1, hi, sum + a[lo], st);
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  dfs(1, n / 2, 0, sumL);
  dfs((n / 2) + 1, n, 0, sumR);
  sort(sumR.begin(), sumR.end());
  for (auto& x : sumL) debug("{} ", x);
  debugln("");
  for (auto& x : sumR) debug("{} ", x);
  debugln("");
  for (auto& u : sumL) {
    int v = upper_bound(sumR.begin(), sumR.end(), m - u) - sumR.begin();
    debugln("{} {}", u, v);
    ans += v;
  }
  println("{}", ans);
  return 0;
}
