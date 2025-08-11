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
constexpr int MAXN = 5e5 + 10;
constexpr int MOD = 998244353;

int n, q;
int a;
int b[MAXN];
set<pii> st;
void solve() {  //
  cin >> n >> q;
  while (q--) {
    cin >> a;
    b[a] ^= 1;
    if (b[a] == 1) {
      int l = a, r = a;
      auto rt = st.upper_bound({a, INF});
      auto lt = st.end();
      if (rt != st.begin()) lt = prev(rt);
      if (rt != st.end()) {
        auto [ll, rr] = *rt;
        if (ll == r + 1) {
          st.erase(rt);
          r = rr;
        }
      }
      if (lt != st.end()) {
        auto [ll, rr] = *lt;
        if (rr == l - 1) {
          st.erase(lt);
          l = ll;
        }
      }
      st.insert({l, r});
    } else {
      auto rt = st.upper_bound({a, INF});
      auto lt = st.end();
      if (rt != st.begin()) lt = prev(rt);
      if (lt != st.end()) {
        auto [ll, rr] = *lt;
        st.erase(lt);
        if (a - 1 >= ll) st.insert({ll, a - 1});
        if (rr >= a + 1) st.insert({a + 1, rr});
      }
    }
    // for (int i = 1; i <= n; ++i) cerr << b[i] << " \n"[i == n];
    // for (auto [l, r] : st) cerr << format("({},{}) ", l, r);
    cout << sz(st) << "\n";
    // cerr.flush();
  }
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
