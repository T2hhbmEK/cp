#include <bits/stdc++.h>
#define int __int128
#define endl '\n'
#define sz(x) (int)(x).size()
#define MOD 998244353
#define MAXN 500010
using namespace std;
using tiii = tuple<int, int, int>;
using pii = tuple<int, int>;
long long x;
int n;
int ans;
ostream& operator<<(ostream& os, int x) {
  if (x == 0) return os << 0;
  stack<signed> s;
  while (x > 0) {
    s.push(x % 10);
    x /= 10;
  }
  while (!s.empty()) os << s.top(), s.pop();
  return os;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> x;
  n = x;
  // cerr << n << endl;
  ans = (n - 2) * (n - 1) / 2;
  // cerr << ans << endl;
  for (int i = 2; i * i <= n; ++i) {
    int j = n / i;
    int nj = n / (i + 1);
    // cerr << i << ": " << j << " " << nj << endl;
    ans -= j - 1;
    if (i == j) j -= 1;
    ans -= (i - 1) * (j - nj);
  }
  cout << ans % MOD << endl;
  return 0;
}
