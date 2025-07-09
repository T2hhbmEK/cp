#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f
#define MAXN 600010
#define endl '\n'
#define YESNO(Y, N)                       \
  inline void Y() { cout << #Y << endl; } \
  inline void N() { cout << #N << endl; }
YESNO(Yes, No)
YESNO(YES, NO)
int b[MAXN];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> b[i];
  int x = 1;
  for (int i = 2; i <= n; ++i) {
    int g = gcd(b[i - 1], b[i]);
    x = lcm(x, b[i - 1] / g);
  }
  cout << x << endl;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
