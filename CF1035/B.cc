#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define MAXN 1010
using namespace std;
inline int rd() {
  int x;
  cin >> x;
  return x;
}
int a[MAXN];
bool solve() {
  int n = rd();
  int px = rd(), py = rd(), qx = rd(), qy = rd();
  int d2 = ((px - qx) * (px - qx)) + ((py - qy) * (py - qy));
  for (int i = 1; i <= n; ++i) a[i] = rd();
  int L = a[1], R = a[1];
  for (int i = 2; i <= n; ++i) {
    int LL = L - a[i];
    int LR = R - a[i];
    int RR = R + a[i];
    if (LL >= 0) {
      L = LL, R = RR;
    } else {  // LL < 0
      if (LR >= 0) {
        L = 0, R = RR;
      } else {
        L = -LR, R = RR;
      }
    }
  }
  return d2 >= L * L && d2 <= R * R;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = rd();
  while (t--) {
    cout << (solve() ? "Yes" : "No") << endl;
  }
  return 0;
}
