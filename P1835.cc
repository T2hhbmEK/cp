#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> primes;
bitset<1000001> not_prime;

bool isPrime(ll x) {
  for (ll i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return x >= 2;
}
/*
 * 2146483647 2147483647
 */
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll L, R;
  cin >> L >> R;
  for (ll i = 1; i * i <= R; ++i) {
    if (isPrime(i)) primes.push_back(i);
  }
  for (auto &p : primes) {
    for (ll i = max(2LL, (L - 1 + p) / p) * p; i <= R; i += p) {
      not_prime[i - L] = 1;
    }
  }
  // for (auto &x : not_primes) cout << x << " ";
  // cout << endl;
  ll ans = 0;
  for (ll i = L; i <= R; ++i) {
    if (!not_prime[i - L] && i != 1) ++ans;
  }
  cout << ans << endl;
  return 0;
}
