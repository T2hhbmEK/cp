#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int main() {
  int n, q;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    sort(a + l, a + r + 1);
  }
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}