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
constexpr int MAXN = 1e5 + 10;
constexpr int MOD = 998244353;

int n, q;
map<int, set<int>> mp;
vi a[MAXN];
int b[MAXN];

void solve() {  //
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) mp[0].insert(i);
  for (int i = 1, x; i <= q; ++i) {
    cin >> x;
    if (x == 0) x = *mp.begin()->second.begin();
    mp[sz(a[x])].erase(x);
    if (mp[sz(a[x])].empty()) mp.erase(sz(a[x]));
    a[x].push_back(i);
    mp[sz(a[x])].insert(x);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j : a[i]) {
      b[j] = i;
    }
  }
  for (int i = 1; i <= q; ++i) cout << b[i] << " \n"[i == q];
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
