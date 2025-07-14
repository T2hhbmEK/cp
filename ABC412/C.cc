#include <bits/stdc++.h>
#define endl '\n'
#define sz(x) (int)(x).size()
using namespace std;
void Yes() { cout << "Yes" << endl; }
void No() { cout << "No" << endl; }
void Ans(int x) { cout << x << endl; }
void solve() {
  int n;
  cin >> n;
  vector<int> s(n);
  for (auto& x : s) cin >> x;
  if (s[n - 1] <= s[0] * 2) return Ans(2);
  sort(s.begin() + 1, s.end() - 1);
  int ans = 2;
  int L = 0, R = n - 1;
  for (int i = 1; i < sz(s) - 1 && s[L] * 2 < s[R]; ++i) {
    if (s[i] <= s[L] * 2 && (i + 1 == R || s[i + 1] > s[L] * 2)) {
      L = i;
      ans += 1;
    }
  }
  if (s[R] > s[L] * 2) return Ans(-1);
  return Ans(ans);
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
