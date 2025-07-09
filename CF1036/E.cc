#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define sz(x) static_cast<int>((x).size())

ostream& operator<<(ostream& os, const vector<int>& a) {
  for (const auto& x : a) os << x << ' ';
  return os;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  int sum = accumulate(a.begin(), a.end(), 0LL);
  int hf = sum >> 1;
  int mx = *max_element(a.begin(), a.end());
  if (sum & 1 || mx > hf) {
    cout << -1 << endl;
    return;
  }
  int pre = 0, md = 0;
  for (int i = 0; i < n; ++i) {
    pre += a[i];
    if (pre == hf) {
      cout << 1 << endl << a << endl;
      return;
    }
    if (pre > hf) {
      md = i;
      break;
    }
  }
  pre -= a[md];
  int pos = sum - pre - a[md];
  vector<int> b(n);
  for (int i = 0, j = n - 1; a[md] < pre + pos;) {
    int t = min({((pre + pos) - a[md]) >> 1, a[i], a[j]});
    a[i] -= t, a[j] -= t, b[i] += t, b[j] += t;
    pre -= t, pos -= t, hf -= t;
    if (a[i] == 0) ++i;
    if (a[j] == 0) --j;
  }
  for (int i = 0; i < md; ++i) b[i] += a[i], a[i] = 0;
  b[md] += pre, a[md] -= pre;
  cout << 2 << endl << a << endl << b << endl;
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
