#include <bits/stdc++.h>
#define endl '\n'
#define sz(x) (int)(x).size()
#define N 200010
#define INF 0x3f3f3f3f
using namespace std;
int n;
char op;
int l, r;
set<pair<int, int>> lr;
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> op;
    if (op == 'A') {
      cin >> l >> r;
      auto it = lr.lower_bound(make_pair(l, 0));
      int cnt = 0;
      while (it != lr.end() && it->first <= r) it = lr.erase(it), ++cnt;
      while (it != lr.begin() && !lr.empty() && prev(it)->second >= l) {
        it = lr.erase(prev(it)), ++cnt;
      }
      lr.insert(make_pair(l, r));
      cout << cnt << endl;
    } else {
      cout << lr.size() << endl;
    }
  }
  return 0;
}
