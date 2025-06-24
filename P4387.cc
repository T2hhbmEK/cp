#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void solve() {
  int n;
  cin >> n;
  queue<int> pushed, poped;
  for (int i = 0, x; i < n; i++) cin >> x, pushed.push(x);
  for (int i = 0, x; i < n; i++) cin >> x, poped.push(x);
  stack<int> s;
  while (!pushed.empty()) {
    s.push(pushed.front()), pushed.pop();
    while (!s.empty() && s.top() == poped.front()) {
      s.pop(), poped.pop();
    }
  }
  if (s.empty() && poped.empty()) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
int main() {
  int q;
  cin >> q;
  while (q--) solve();
  return 0;
}
