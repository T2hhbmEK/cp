#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using i64 = long long;
constexpr i64 mod = 666623333;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  i64 l, r;
  cin >> l >> r;
  i64 n = r - l + 1;
  vector<i64> a(n), p(n);
  iota(a.begin(), a.end(), l);
  iota(p.begin(), p.end(), l);
  i64 m = sqrt(r) + 1;
  vector<bool> not_prime(m, false);
  not_prime[0] = not_prime[1] = true;
  vector<i64> primes;
  for (i64 i = 2; i * i <= r; ++i) {
    if (!not_prime[i]) primes.push_back(i);
    for (i64 j = 0; j < (i64)primes.size() && i * primes[j] <= m; ++j) {
      not_prime[i * primes[j]] = true;
      if (i % primes[j] == 0) break;
    }
  }
  for (auto& i : primes) {
    for (i64 j = (l - 1 + i) / i * i; j <= r; j += i) {
      if (a[j - l] % i == 0) {
        p[j - l] /= i;
        p[j - l] *= (i - 1);
        while (a[j - l] % i == 0) a[j - l] /= i;
      }
    }
  }
  i64 sum = 0;
  for (i64 i = l; i <= r; ++i) {
    if (a[i - l] > 1) {
      p[i - l] /= a[i - l];
      p[i - l] *= (a[i - l] - 1);
    }
    sum += i - p[i - l];
    sum %= mod;
  }
  cout << sum << endl;
  return 0;
}
