#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;
int m, n;
int trie[MAXN][2], cnt;
int exist[MAXN];
int f[MAXN];
void add(vector<int>& a) {
  int p = 0;
  for (auto& x : a) {
    if (trie[p][x] == 0) trie[p][x] = ++cnt;
    p = trie[p][x];
    f[p] += 1;
  }
  exist[p] += 1;
}
int find(vector<int>& a) {
  int p = 0, ret = 0;
  for (auto& x : a) {
    p = trie[p][x];
    if (p == 0) break;
    ret += exist[p];
  }
  ret += f[p] - exist[p];
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> m >> n;
  for (int i = 1, k; i <= m; ++i) {
    cin >> k;
    vector<int> b(k);
    for (auto& x : b) cin >> x;
    add(b);
  }
  // for (int i = 0; i <= cnt; ++i) {
  //   cerr << i << ' ' << trie[i][0] << ' ' << trie[i][1] << '\n';
  // }
  for (int j = 1, k; j <= n; ++j) {
    cin >> k;
    vector<int> c(k);
    for (auto& x : c) cin >> x;
    cout << find(c) << '\n';
  }
  return 0;
}
