#include <bits/stdc++.h>
#define int long long
#define maxn 200010
using namespace std;

int n, a[maxn], c, ans;

signed main() {
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= 2 * n; i++) {
    cin >> c;
    ans += c;
    a[i] -= c;
  }
  sort(a + 1, a + 1 + 2 * n, greater<int>());
  for (int i = 1; i <= n; i++) {
    ans += a[i];
  }
  cout << ans << '\n';
  return 0;
}
