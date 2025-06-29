#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
constexpr int mod = 1e9 + 7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> m(n);
  for (auto& x : m) cin >> x;
  sort(all(m));
  ll ans = 1;
  rep(i, sz(m))(ans *= max(0, m[i] - i)) %= mod;
  cout << ans << endl;
  return 0;
}
