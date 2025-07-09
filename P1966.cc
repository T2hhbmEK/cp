#include <bits/stdc++.h>
#define MOD 99999997
#define MAXN 100010
using namespace std;

struct Item {
  int i, a, b;
};

int n, ans, a_rnk_to_ind[MAXN], b_ind_to_a_ind[MAXN];
Item s[MAXN];

void msort(int a[], int lo, int hi) {
  static int t[MAXN];
  if (lo >= hi) return;
  int mi = lo + ((hi - lo) >> 1);
  msort(a, lo, mi), msort(a, mi + 1, hi);
  int i = lo, j = lo, k = mi + 1;
  while (j <= mi && k <= hi) {
    if (a[k] < a[j]) (ans += mi - j + 1) %= MOD;
    t[i++] = a[k] < a[j] ? a[k++] : a[j++];
  }
  while (j <= mi) t[i++] = a[j++];
  while (k <= hi) t[i++] = a[k++];
  for (int i = lo; i <= hi; ++i) a[i] = t[i];
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> s[i].a;
  for (int i = 1; i <= n; ++i) cin >> s[i].b;
  for (int i = 1; i <= n; ++i) s[i].i = i;
  sort(s + 1, s + 1 + n, [](auto& x, auto& y) { return x.a < y.a; });
  for (int i = 1; i <= n; ++i) a_rnk_to_ind[i] = s[i].i;
  sort(s + 1, s + 1 + n, [](auto& x, auto& y) { return x.b < y.b; });
  for (int i = 1; i <= n; ++i) b_ind_to_a_ind[s[i].i] = a_rnk_to_ind[i];
  msort(b_ind_to_a_ind, 1, n);
  cout << ans << '\n';
  return 0;
}
