#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define sz(x) (int)(x).size()
#define MAXN 500010
using namespace std;
using tiii = tuple<int, int, int>;
using pii = tuple<int, int>;
int n, m;
int x[MAXN];
pii a[MAXN];
int vis[MAXN], sum;
int ans;
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> x[i];
  sort(x + 1, x + 1 + n);
  for (int i = 1; i < n; ++i) a[i] = {x[i + 1] - x[i], i};
  sort(a + 1, a + n);
  for (int j = 1; j <= n - m; ++j) {
    auto& [d, i] = a[j];
    ans += d;
  }
  cout << ans << endl;
  return 0;
}
