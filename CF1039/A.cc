#include <bits/stdc++.h>
using namespace std;

// #define int __int128
#define sz(x) (int)(x).size()
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using pq = priority_queue<int, vi, greater<>>;

constexpr int INF = numeric_limits<int>::max();
constexpr int MAXN = 2e5 + 10;

string s;

void init() {  //
}

void solve() {  //
  cin >> s;
  int cntT = 0, cntN = 0;
  for (char ch : s) {
    if (ch == 'T') ++cntT;
    if (ch == 'N') ++cntN;
  }
  while (cntT--) cout << 'T';
  for (char ch : s) {
    if (ch != 'T' && ch != 'N') cout << ch;
  }
  while (cntN--) cout << 'N';
  cout << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  init();
  while (t--) solve();
  return 0;
}
