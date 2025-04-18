#include <bits/stdc++.h>
#define maxn 100'010
using namespace std;

int n, x, a[maxn], f[maxn], ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) f[cin >> x, x] = i;
  for (int i = 1; i <= n; i++) a[i] = f[cin >> x, x];
  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= n; i++) {
    int j = upper_bound(f + 1, f + 1 + ans, a[i]) - f;
    f[j] = min(f[j], a[i]);
    ans = max(ans, j);
  }
  // for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
  // for (int i = 1; i <= n; i++) cout << f[i] << " \n"[i == n];
  cout << ans;
  return 0;
}
