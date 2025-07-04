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
  for (int i = 0; i < n; ++i) {
    while (!q.empty() && a[q.back()] > a[i]) q.pop_back();
    q.push_back(i);
    if (i - k + 1 < 0) continue;
    while (!q.empty() && q.front() <= i - k) q.pop_front();
    cout << a[q.front()] << ' ';
  }
  cout << '\n';
  q.clear();
  for (int i = 0; i < n; ++i) {
    while (!q.empty() && a[q.back()] < a[i]) q.pop_back();
    q.push_back(i);
    if (i - k + 1 < 0) continue;
    while (!q.empty() && q.front() <= i - k) q.pop_front();
    cout << a[q.front()] << ' ';
  }
  cout << '\n';
  return 0;
}
