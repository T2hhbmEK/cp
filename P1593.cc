#include <cassert>
#include <iostream>
#include <unordered_map>
using namespace std;
using i64 = long long;
using Fac = unordered_map<i64, i64>;
constexpr i64 mod = 9901;
constexpr i64 smod = (1 + mod - 1) * (mod - 1) / 2 % mod;

Fac Factorize(i64 n) {
  Fac f;
  for (i64 i = 2; i * i <= n; ++i) {
    while (n % i == 0) ++f[i], n /= i;
  }
  if (n > 1) ++f[n];
  return f;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  i64 a, b;
  cin >> a >> b;
  i64 sum = 1;
  Fac factors = Factorize(a);
  for (auto& [k, v] : factors) v *= b;
  for (auto& [k, v] : factors) {
    i64 s = smod * (v / (mod - 1)) % mod;
    for (i64 i = 0, a = 1; i <= v % (mod - 1); ++i, a = a * k % mod) {
      s = (s + a) % mod;
    }
    sum = (sum * s) % mod;
  }
  cout << sum << endl;
  return 0;
}
