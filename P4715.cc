#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int main() {
  int n;
  cin >> n;
  n = 1 << n;
  queue<pair<int, int>> q;
  for (int i = 1, x; i <= n; ++i) cin >> x, q.push({x, i});
  auto pop = [&]() {
    auto ret = q.front();
    q.pop();
    return ret;
  };
  while (q.size() > 2) {
    q.push(max(pop(), pop()));
  }
  cout << min(pop(), pop()).second << endl;
  return 0;
}
