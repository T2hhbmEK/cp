#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

int n;
vector<pii> a;
vector<int> lt, gt;
vector<pii> t;

void work(int l, int r) {
  if (r <= l + 1) return;
  int m = l + (r - l) / 2;
  work(l, m), work(m, r);
  for (int i = l; i < m; ++i) {
    auto& [val, ind] = a[i];
    auto x = make_pair(a[i].first, numeric_limits<int>::max());
    int jj = upper_bound(a.begin() + m, a.begin() + r, x) - a.begin();
    gt[ind] += r - jj;
  }
  for (int i = m; i < r; ++i) {
    auto& [val, ind] = a[i];
    auto x = make_pair(a[i].first, numeric_limits<int>::min());
    int ii = lower_bound(a.begin() + l, a.begin() + m, x) - a.begin();
    lt[ind] += ii - l;
  }
  merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin() + l);
  copy(t.begin() + l, t.begin() + r, a.begin() + l);
}

void solve() {
  cin >> n;
  a.resize(n);
  for (int i = 0; auto& [x, y] : a) cin >> x, y = i++;
  lt.resize(n), gt.resize(n), t.resize(n);
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < i; ++j) {
  //     if (a[j].first < a[i].first) lt[i] += 1;
  //   }
  //   for (int j = i + 1; j < n; ++j) {
  //     if (a[i].first < a[j].first) gt[i] += 1;
  //   }
  // }
  // for (auto& x : lt) cout << x << " \n"[&x == &lt.back()];
  // for (auto& x : gt) cout << x << " \n"[&x == &gt.back()];
  // {
  //   int ans = 0;
  //   for (int i = 0; i < n; ++i) {
  //     ans += lt[i] * gt[i];
  //   }
  //   cout << ans << '\n';
  // }
  // lt.assign(n, 0), gt.assign(n, 0);
  work(0, n);
  // for (auto& x : lt) cout << x << " \n"[&x == &lt.back()];
  // for (auto& x : gt) cout << x << " \n"[&x == &gt.back()];
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += lt[i] * gt[i];
  }
  cout << ans << '\n';
}

void test() {
  constexpr int maxn = 20;
  random_device rd;
  mt19937 gen(rd());
  auto dist = uniform_int_distribution<int>(1, maxn + 1);
  n = dist(gen);
  cerr << n << '\n';
  a.resize(n);
  for (int i = 0; auto& [x, y] : a) x = dist(gen), y = i++;
  for (auto& [x, y] : a) cerr << x << ' ';
  cerr << '\n';
  int ans = 0;
  for (auto i = a.begin(); i != a.end(); ++i) {
    for (auto j = i + 1; j != a.end(); ++j) {
      for (auto k = j + 1; k != a.end(); ++k) {
        if (i->first < j->first && j->first < k->first) {
          ans += 1;
        }
      }
    }
  }
  cerr << ans << '\n';
  solve();
  exit(0);
}

signed main() {
  // test();
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
