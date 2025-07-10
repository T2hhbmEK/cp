#include <bits/stdc++.h>
#define MAXN 1000010
#define MAXL 20
using namespace std;
int n, k, ans, a[MAXN];
int trie[MAXN * MAXL][2], tot, siz[MAXN * MAXL], exist[MAXN * MAXL];
void add(int a) {
  int p = 0;
  for (int i = MAXL; i >= 0; --i) {
    int j = (a >> i) & 1;
    if (trie[p][j] == 0) trie[p][j] = ++tot;
    p = trie[p][j];
    siz[p] += 1;
  }
  exist[p] += 1;
}
int work(int x) {
  int p = 0;
  int sum = 0;
  for (int i = MAXL; i >= 0; --i) {
    int u = (x >> i) & 1;
    int v = (k >> i) & 1;
    if (v == 1) sum += siz[trie[p][0 ^ u]];
    p = trie[p][v ^ u];
    if (p == 0) return sum;
  }
  sum += siz[p];  // <= k
  return sum;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i], add(a[i]);
  for (int x = 0; x <= (1 << MAXL); ++x) {
    ans = max(ans, work(x));
  }
  cout << ans << '\n';
  return 0;
}
