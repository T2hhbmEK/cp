#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& [d, w] : a) cin >> d >> w;
  int cnt = 0;
  stack<int> s;
  for (auto& [d, w] : a) {
    while (!s.empty() && s.top() > w) ++cnt, s.pop();
    while (!s.empty() && s.top() == w) s.pop();
    s.push(w);
  }
  cnt += s.size();
  cout << cnt << endl;
  return 0;
}
