#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct Ship {
  int t, k;
  vector<int> x;
};
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<Ship> a(n);
  unordered_map<int, int> mp;
  for (auto& u : a) {
    cin >> u.t >> u.k;
    u.x.resize(u.k);
    for (auto& v : u.x) cin >> v;
  }
  for (auto i = a.begin(), j = a.begin(); j != a.end(); ++j) {
    while (i->t <= j->t - 86400) {
      for (auto& u : i->x) {
        if (--mp[u] == 0) mp.erase(mp.find(u));
      }
      ++i;
    }
    for (auto& u : j->x) ++mp[u];
    cout << mp.size() << '\n';
  }
  return 0;
}
