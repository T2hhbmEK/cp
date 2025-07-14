#include <bits/stdc++.h>
#define endl '\n'
#define sz(x) (int)(x).size()
using namespace std;
int n, ans;
void solve() {
  cin >> n;
  for (int i = 0, a, b; i < n; ++i) {
    cin >> a >> b;
    ans += b > a;
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
