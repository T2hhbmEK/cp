#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  unordered_map<int, int> mp;
  int d = 0x3f3f3f3f, x = 0, y = 0;
  for (auto it = a.begin(), jt = a.begin(); jt != a.end(); ++jt) {
    ++mp[*jt];
    if (static_cast<int>(mp.size()) < m) continue;
    while (mp[*it] > 1) --mp[*it], ++it;
    if (jt - it + 1 < d) {
      d = jt - it + 1;
      x = it - a.begin() + 1;
      y = jt - a.begin() + 1;
    }
  }
  cout << x << " " << y << endl;
  return 0;
}
