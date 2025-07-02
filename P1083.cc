#include <algorithm>
#include <cstring>
#include <iostream>
#define maxn 1000010
using namespace std;

int n, m, r[maxn], d[maxn], s[maxn], t[maxn];
int df[maxn];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> r[i];
  for (int i = n; i >= 1; --i) r[i] -= r[i - 1];
  for (int i = 1; i <= m; ++i) cin >> d[i] >> s[i] >> t[i], t[i] += 1;
  int lo = 0, hi = m;
  while (lo < hi) {
    int md = lo + (hi - lo + 1) / 2;
    memcpy(df, r, sizeof(r));
    for (int i = 1; i <= md; ++i) df[s[i]] -= d[i], df[t[i]] += d[i];
    for (int i = 1; i <= n; ++i) df[i] += df[i - 1];
    int mn = *min_element(df + 1, df + 1 + n);
    if (mn >= 0) {
      lo = md;
    } else {
      hi = md - 1;
    }
  }
  if (lo < m) {
    cout << -1 << endl;
    cout << lo + 1 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
