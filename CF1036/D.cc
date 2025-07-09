#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f
#define endl '\n'
#define sz(x) static_cast<int>((x).size())

bool solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (auto& x : a) cin >> x;
  iota(b.begin(), b.end(), 0);
  sort(b.begin(), b.end(), [&a](int i, int j) { return a[i] < a[j]; });
  int x = a[b[k - 1]];  // kth
  b.clear();
  for (auto& y : a) {
    if (y <= x) b.push_back(y);
  }
  int m = sz(b);
  int rm = 0;
  for (int i = 0, j = m - 1; i < j;) {
    if (b[i] == b[j]) {
      ++i, --j;
    } else if (b[i] == x) {
      ++rm, ++i;
    } else if (b[j] == x) {
      ++rm, --j;
    } else {
      return false;
    }
  }
  return m - rm >= k - 1;
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) cout << (solve() ? "YES" : "NO") << endl;
  return 0;
}
