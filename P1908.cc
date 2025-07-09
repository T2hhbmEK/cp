#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;

int n, a[MAXN], t[MAXN];
int64_t ans;

void merge_sort(int lo, int hi) {
  if (lo >= hi) return;
  int mi = (lo + hi) >> 1;
  merge_sort(lo, mi);
  merge_sort(mi + 1, hi);
  int i = lo, j = lo, k = mi + 1;
  for (; j <= mi && k <= hi; ++i) {
    if (a[k] < a[j]) ans += mi - j + 1;
    t[i] = a[k] < a[j] ? a[k++] : a[j++];
  }
  for (; j <= mi; ++i, ++j) t[i] = a[j];
  for (; k <= hi; ++i, ++k) t[i] = a[k];
  for (int i = lo; i <= hi; ++i) a[i] = t[i];
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  merge_sort(1, n);
  cout << ans << '\n';
  return 0;
}
