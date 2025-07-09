#include <bits/stdc++.h>
#define MAXN 300010
#define endl '\n'
using namespace std;
int t;
int n;
int a[MAXN];
void work(int lo, int hi) {
  if (hi - lo <= 1) return;
  int mi = lo + ((hi - lo) >> 1);
  work(lo, mi), work(mi, hi);
  if (a[lo] > a[mi]) {
    for (int i = lo, j = mi; i < mi; ++i, ++j) {
      swap(a[i], a[j]);
    }
  }
}
void solve() {
  cin >> n;
  n = 1 << n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  work(0, n);
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
