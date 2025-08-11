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

int a, b, k;

void solve() {  //
  cin >> a >> b >> k;
  int g = __gcd(a, b);
  int dx = a / g, dy = b / g;
  if (dx <= k && dy <= k) {
    cout << 1 << '\n';
    return;
  }
  // 1,1 followed by 1,0 or 0,1
  cout << 2 << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  init();
  while (t--) solve();
  return 0;
}
