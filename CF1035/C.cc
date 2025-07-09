#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define MAXN 1010
using namespace std;
inline int rd() {
  int x = 0;
  cin >> x;
  return x;
}
inline int f(int x) {
  int cnt = 0;
  while (x != 0) {
    x = x >> 1;
    ++cnt;
  }
  return cnt;
}
int solve() {
  int n, l, r, k;
  cin >> n >> l >> r >> k;
  if (n % 2 != 0) return l;
  if (n == 2) return -1;
  int x = 1LL << f(l);
  if (x > r) return -1;
  if (k <= n - 2) return l;
  return x;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while ((t--) != 0) {
    cout << solve() << endl;
  }
  return 0;
}
