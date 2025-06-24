#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
constexpr int inf = 0x3f3f3f3f;
using ll = long long;
using vi = vector<int>;
int main() {
  int m, n;
  cin >> m >> n;
  vi a(m);
  for (auto& x : a) cin >> x;
  a.push_back(-inf);
  a.push_back(+inf);
  sort(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0, b; i < n; i++) {
    cin >> b;
    auto it = lower_bound(a.begin(), a.end(), b);
    ans += min(b - *(it - 1), *it - b);
  }
  cout << ans << endl;
  return 0;
}
