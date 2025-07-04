#include <array>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;
using i64 = long long;
constexpr i64 mod = 10007;
struct Item {
  i64 ind, num, col;
};
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  i64 n, m;
  cin >> n >> m;
  vector<Item> a(n);
  for (i64 i = 0; auto& [ind, num, col] : a) ind = ++i;
  for (auto& [ind, num, col] : a) cin >> num;
  for (auto& [ind, num, col] : a) cin >> col;
  unordered_map<i64, array<vector<Item>, 2>> mp;
  for (auto& x : a) mp[x.col][x.ind % 2].push_back(x);
  i64 ans = 0;
  for (auto& [col, _] : mp) {
    for (i64 parity : {0, 1}) {
      auto& s = mp[col][parity];
      // cerr << col << " " << parity << " ";
      // for (auto& [x, num, _] : s) cerr << "{" << x << "," << num << "} ";
      // cerr << endl;
      i64 k = s.size();
      i64 sum = 0;
      for (auto& [x, num, _] : s) sum += num;
      for (auto& [x, num, _] : s) (ans += x * num * (k - 1)) %= mod;
      for (auto& [x, num, _] : s) (ans += x * (sum - num)) %= mod;
      // cerr << ans << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
