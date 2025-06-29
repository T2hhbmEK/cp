#include <cassert>
#include <iostream>
#include <ostream>
#include <stack>
using namespace std;
using ll = long long;

ll dp[64][64];
ll comb_(ll n, ll m) {
  if (n < 0 || m < 0 || m > n) return 0;
  if (m > n - m) m = n - m;
  ll ret = 1;
  for (ll i = n; i > n - m; --i) ret *= i;
  for (ll i = m; i > 0; --i) ret /= i;
  return ret;
}
ll comb(ll n, ll m) {
  if (n < 0 || m < 0 || m > n) return 0;
  if (dp[n][m]) return dp[n][m];
  if (n == 0 && m == 0) return dp[n][m] = 1;
  return dp[n][m] = comb(n - 1, m - 1) + comb(n - 1, m);
}
ostream& operator<<(ostream& os, __int128 x) {
  stack<int> st;
  while (x) {
    st.push(x % 10);
    x /= 10;
  }
  while (!st.empty()) {
    os << st.top();
    st.pop();
  }
  return os;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, a, b;
  cin >> n >> a >> b;
  __int128 sa = 0, sb = 0;
  for (ll i = 0; i <= a; ++i) sa += comb(n + i - 1, i);
  for (ll i = 0; i <= b; ++i) sb += comb(n + i - 1, i);
  cout << sa * sb << endl;
  return 0;
}
