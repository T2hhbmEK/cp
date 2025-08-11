#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)(x).size()
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using vpii = vector<pii>;
using pq = priority_queue<int, vi, greater<>>;

void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }

constexpr int INF = numeric_limits<int>::max();
constexpr int MAXN = 2e5 + 10;
constexpr int MOD = 998244353;

int n;
int a[MAXN], b[MAXN];
int x[MAXN * 2];

void solve() {  //
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    x[a[i]] = b[i];
    x[b[i]] = a[i];
  }
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
