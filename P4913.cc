#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& x : a) cin >> x.first >> x.second;
  a.insert(a.begin(), {0, 0});
  function<int(int)> dfs = [&](int i) {
    return i == 0 ? 0 : 1 + max(dfs(a[i].first), dfs(a[i].second));
  };
  cout << dfs(1) << endl;
  return 0;
}
