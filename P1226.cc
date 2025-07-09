#include <bits/stdc++.h>
using namespace std;
int64_t a, b, p, ans = 1;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> a >> b >> p;
  cout << a << "^" << b << " mod " << p << "=";
  while (b != 0) {
    if ((b & 1) != 0) ans *= a, ans %= p;
    a *= a, a %= p;
    b = b >> 1;
  }
  cout << ans << '\n';
  return 0;
}
