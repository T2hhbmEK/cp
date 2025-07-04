#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  deque<int> q;
  for (int i = 0, j = 0; j < n; ++j) {
    while (!q.empty() && a[q.back()] < a[j]) q.pop_back();
    q.push_back(j);
    while (!q.empty() && q.front() < i) q.pop_front();
    if (j - i + 1 < k) continue;
    cout << a[q.front()] << '\n';
    ++i;
  }
  return 0;
}
