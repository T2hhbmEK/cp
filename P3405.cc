#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <utility>
using namespace std;
using ll = long long;
int n;
ll m, ans;
map<pair<string, string>, ll> mp;
string ct, st;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> ct >> st;
    mp[{ct.substr(0, 2), st}] += 1;
  }
  for (auto &p : mp) {
    tie(ct, st) = p.first, m = p.second;
    if (ct < st) {
      ans += m * mp[{st, ct}];
    }
  }
  cout << ans << endl;
  return 0;
}
