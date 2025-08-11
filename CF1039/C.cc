#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)(x).size()
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using pq = priority_queue<int, vi, greater<>>;

constexpr int INF = numeric_limits<int>::max();
constexpr int MAXN = 2e5 + 10;

void init() {  //
}

int l, r;

int f(int x) { return r / x - (l - 1 + x) / x + 1; }

void solve() {  //
  cin >> l >> r;
  int sum = 0;
  int a[] = {2, 3, 5, 7};
  for (int i : a) sum += f(i);
  for (int i : a) {
    for (int j : a) {
      if (j > i) sum -= f(i * j);
    }
  }
  for (int i : a) {
    for (int j : a) {
      for (int k : a) {
        if (j > i && k > j) sum += f(i * j * k);
      }
    }
  }
  sum -= f(2 * 3 * 5 * 7);
  cout << r - l + 1 - sum << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  init();
  while (t--) solve();
  return 0;
}
