#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)(x).size()
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using pq = priority_queue<int, vi, greater<>>;

void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }

constexpr int INF = numeric_limits<int>::max();
constexpr int MAXN = 1e6 + 10;
constexpr int MOD = 998244353;

int n, q;
int a[MAXN];
int op, p, x, k;
int of;

void solve() {  //
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) a[i] = i;
  while (q--) {
    cin >> op;
    if (op == 1) {
      cin >> p >> x;
      a[(p + of - 1) % n + 1] = x;
    } else if (op == 2) {
      cin >> p;
      cout << a[(p + of - 1) % n + 1] << '\n';
    } else {
      cin >> k;
      (of += k) %= n;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
