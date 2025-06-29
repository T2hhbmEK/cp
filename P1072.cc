#include <iostream>
#include <set>
using namespace std;
using i32 = int;
using i64 = long long;

/*
 * gcd(x, a0)=a1 -> x=u0*a1, a0=v0*a1
 *                  gcd(u0, v0)=1
 *                  gcd(x/a1,a0/a1)=1
 * lcm(x, b0)=b1 -> x=u1*g1, b0=v1*g1, b1=u1*v1*g1
 *                  gcd(u1, v1)=1
 *                  gcd(b1/b0,b1/x)=1
 */

i64 gcd(i64 a, i64 b) { return b == 0 ? a : gcd(b, a % b); }
i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  i64 n, a0, a1, b0, b1;
  cin >> n;
  while (n--) {
    cin >> a0 >> a1 >> b0 >> b1;
    if (b1 % a1 != 0) {
      cout << 0 << '\n';
    } else {
      // x=a1*factors_of_(y) y=b1/a1
      i64 y = b1 / a1, ans = 0;
      for (i64 i = 1; i * i <= y; ++i) {
        if (y % i == 0) {
          for (auto z : set({i, y / i})) {
            if (gcd(z, a0 / a1) == 1 && gcd(b1 / b0, y / z) == 1) ++ans;
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
