#include <iostream>
using namespace std;
using i64 = long long;

i64 gcd(i64 x, i64 y, i64& sum) {
  if (y == 0) return x;
  sum += x / y * 4 * y;
  return gcd(y, x % y, sum);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  i64 x, y;
  cin >> x >> y;
  i64 sum = 0;
  i64 _ = gcd(x, y, sum);
  cout << sum << endl;
  return 0;
}
