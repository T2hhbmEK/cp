#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define sz(x) (int)(x).size()
#define MAXN 100000
using namespace std;
int n, l, r, x, y, ans;
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> l >> r;
  if (r < l) r += 24;
  for (int i = 1; i <= n; ++i) {
    cin >> x >> y;
    if (y < x) y += 24;
    if (x <= l && y >= r) ++ans;
  }
  cout << ans << endl;
  return 0;
}
