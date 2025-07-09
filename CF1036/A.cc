#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f
#define MAXN 100010
#define endl '\n'
#define YESNO(Y, N)                       \
  inline void Y() { cout << #Y << endl; } \
  inline void N() { cout << #N << endl; }
YESNO(Yes, No)
YESNO(YES, NO)
int a[MAXN], b[MAXN];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) b[i] = a[i];
  sort(b + 1, b + 1 + n);
  int ans = n;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == b[i]) {
      a[i] = b[i] = 0;
      ans -= 1;
    }
  }
  if (ans > 0) {
    YES();
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
      if (a[i] != 0) cout << a[i] << ' ';
    }
    cout << endl;
  } else {
    NO();
  }
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
