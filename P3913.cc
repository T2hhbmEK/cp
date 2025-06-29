#include <iostream>
#include <unordered_set>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  unordered_set<ll> rs, cs;
  while (k--) {
    ll r, c;
    cin >> r >> c;
    rs.insert(r);
    cs.insert(c);
  }
  cout << n * n - (n - rs.size()) * (n - cs.size()) << endl;
  return 0;
}
