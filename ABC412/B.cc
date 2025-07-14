#include <bits/stdc++.h>
#define endl '\n'
#define sz(x) (int)(x).size()
using namespace std;
void Yes() { cout << "Yes" << endl; }
void No() { cout << "No" << endl; }
void solve() {
  string s, t;
  cin >> s >> t;
  set<char> ts(t.begin(), t.end());
  for (int i = 1; i < sz(s); ++i) {
    if (isupper(s[i - 1])) {
      if (!ts.contains(s[i])) return No();
    }
  }
  return Yes();
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
