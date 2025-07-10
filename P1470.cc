#include <bits/stdc++.h>
#define MAXN 200010
#define sz(x) (int)(x).size()
using namespace std;
string x, a[MAXN], s;
int n;
int cnt, nex[MAXN][26];
bool exist[MAXN];
void add(const string &s) {
  int p = 0;
  for (char c : s) {
    int j = c - 'A';
    if (nex[p][j] == 0) nex[p][j] = ++cnt;
    p = nex[p][j];
  }
  exist[p] = true;
}
bool dp[MAXN];
void work(int k) {
  int p = 0;
  for (int i = k; i < sz(s); ++i) {
    p = nex[p][s[i] - 'A'];
    if (p == 0) break;
    // cerr << s[i] << ' ';
    if (exist[p]) {
      dp[i + 1] = true;
    }
  }
  // cerr << '\n';
}
int ans;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  while (cin >> x && x != ".") a[++n] = x;
  while (cin >> x) s += x;
  for (int i = 1; i <= n; ++i) add(a[i]);
  // for (int i = 0; i < cnt; ++i) {
  //   for (int j = 0; j < 26; ++j) {
  //     if (nex[i][j] != 0) {
  //       cerr << i << ' ' << char('A' + j) << ' ';
  //       cerr << nex[i][j] << ' ';
  //       if (exist[nex[i][j]]) cerr << 1 << ' ';
  //       cerr << '\n';
  //     }
  //   }
  // }
  dp[0] = true;
  for (int i = 0; i <= sz(s); ++i) {
    if (dp[i]) {
      ans = i;
      work(i);
    }
  }
  cout << ans << '\n';
  return 0;
}
