#include <algorithm>
#include <iostream>
#include <vector>
#define maxn 10010
using namespace std;
vector<int> e[maxn];
int a[maxn], dp[maxn], ans;
int f(int u) {
  if (dp[u]) return dp[u];
  int mx = 0;
  for (auto& v : e[u]) {
    mx = max(mx, f(v));
  }
  return dp[u] = mx + a[u];
}
int main() {
  int n;
  cin >> n;
  for (int i = 1, u, v; i <= n; ++i) {
    cin >> u >> a[u];
    while (cin >> v && v) e[u].push_back(v);
  }
  for (int i = 1; i <= n; ++i) ans = max(ans, f(i));
  cout << ans << endl;
  return 0;
}
