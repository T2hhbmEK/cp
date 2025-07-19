#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define MAXN 110

void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }

string s;
void solve() {
  cin >> s;
  queue<int> q;
  for (int i = 1; i <= sz(s); ++i) {
    if (s[i - 1] == '#') q.push(i);
  }
  while (!q.empty()) {
    cout << q.front() << ",";
    q.pop();
    cout << q.front() << "\n";
    q.pop();
  }
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
