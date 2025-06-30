#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>
#include <unordered_map>
#include <vector>
using namespace std;
using Factors = unordered_map<int, int>;
void dfs(const Factors::iterator be, const Factors::iterator en, int prod,
         vector<int>& cnt) {
  if (be == en) {
    ++cnt[prod];
    return;
  }
  dfs(next(be), en, prod, cnt);
  for (int i = 1; i <= be->second; ++i) {
    prod *= be->first;
    dfs(next(be), en, prod, cnt);
  }
}
ostream& operator<<(ostream& os, Factors a) {
  for (auto& [k, v] : a) {
    os << k << ":" << v << " ";
  }
  return os;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  int mx = *max_element(a.begin(), a.end());
  vector<int> cnt(mx + 1, 0);
  for (auto& x : a) {
    Factors factors;
    for (int i = 2; i * i <= x; ++i) {
      while (x % i == 0) {
        ++factors[i];
        x /= i;
      }
    }
    if (x > 1) ++factors[x];
    dfs(factors.begin(), factors.end(), 1, cnt);
  }
  for (int i = mx, k = 1; i >= 1 && k <= n;) {
    if (cnt[i] >= k) {
      cout << i << '\n';
      ++k;
    } else {
      --i;
    }
  }
  return 0;
}
