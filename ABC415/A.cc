#include <bits/stdc++.h>
using namespace std;

#define MAXN 110

void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }

int n, x;

void solve() {
  cin >> n;
  set<int> a;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    a.insert(x);
  }
  cin >> x;
  return a.contains(x) ? Yes() : No();
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
