#include <algorithm>
#include <deque>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
/*
5 2
-1 -2 -3 -4 -5
 */
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> p(n + 1, 0);
  for (int i = 1; i <= n; ++i) cin >> p[i];
  int ans = numeric_limits<int>::min();
  for (int i = 1; i <= n; ++i) p[i] += p[i - 1];
  deque<int> q = {0};
  for (int i = 1; i <= n; ++i) {
    while (q.front() < i - m) q.pop_front();
    ans = max(ans, p[i] - p[q.front()]);
    while (!q.empty() && p[q.back()] >= p[i]) q.pop_back();
    q.push_back(i);
  }
  cout << ans << endl;
  return 0;
}
