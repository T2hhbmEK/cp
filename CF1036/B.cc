#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f
#define MAXN 200010
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
  for (int i = 2; i <= n; ++i) b[i] = min(b[i], b[i - 1]);
  int ans = accumulate(b + 1, b + 1 + n, 0LL);
  int sum = 0, fnd = 0;  // find a[i] not contribute to min
  for (int i = 1; i <= n; ++i) {
    if (i == 1) {
      // nothing
    } else if (i == 2) {
      // add a[2] to a[1] and set a[2] to zero
      int tmp = a[1] + a[2];
      ans = min(ans, tmp);
    }
    if (i >= 2) {
      // set a[i] to zero
      if (fnd) {
        int tmp = sum;
        ans = min(ans, tmp);
      } else {
        // every a[j], j < i contribue to min
        // add a[i] to any one of them will make sum -> sum + a[i]
        int tmp = sum + a[i];
        ans = min(ans, tmp);
      }
      if (a[i] >= b[i - 1]) fnd = 1;
    }
    sum += b[i];  // presum of b[1] ... b[i-1]
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
