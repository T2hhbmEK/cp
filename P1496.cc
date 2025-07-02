#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> s(n);
  set<int> t;
  for (auto& [a, b] : s) {
    cin >> a >> b;
    t.insert(a);
    t.insert(b);
  }
  vector<int> v(t.begin(), t.end());
  vector<int> dif(v.size());
  for (auto& [a, b] : s) {
    int lo = distance(v.begin(), lower_bound(v.begin(), v.end(), a));
    int hi = distance(v.begin(), lower_bound(v.begin(), v.end(), b));
    ++dif[lo];
    --dif[hi];
  }
  for (int i = 1; i < (int)dif.size(); ++i) dif[i] += dif[i - 1];
  int sum = 0;
  for (int i = 0; i < (int)v.size(); ++i) {
    if (dif[i] > 0) sum += v[i + 1] - v[i];
  }
  cout << sum << endl;
  return 0;
}
