#include <bits/stdc++.h>
#define int __int128
#define endl '\n'
#define sz(x) (int)(x).size()
#define MOD 998244353
#define MAXN 500010
using namespace std;
using tiii = tuple<int, int, int>;
using pii = tuple<int, int>;
int n;
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
int bf() {
  int ans = (n - 2) * (n - 1) / 2;
  for (int i = 2; i < n; ++i) {
    int j = n / i;
    ans -= j - 1;
  }
  return ans;
}
int solve() {
  int ans = (n - 2) * (n - 1) / 2;
  for (int i = 2; i * i <= n; ++i) {
    int j = n / i;
    int nj = n / (i + 1);
    // nj < k <= j, i < k
    ans -= j - 1;
    ans -= (i - 1) * max((j - max(i, nj)), int(0));
    // cerr << i << ": (" << nj << "," << j << "]" << endl;
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long x;
  cin >> x;
  n = x;
  cout << solve() % MOD << endl;
  // cout << bf() % MOD << endl;
  return 0;
}
