#include <algorithm>
#include <cstdlib>
#include <iostream>
#define maxn 100010
#define i64 long long
using namespace std;
i64 n, a[maxn];
i64 up, dn;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (i64 i = 1; i <= n; ++i) cin >> a[i];
  for (i64 i = 2; i <= n; ++i) {
    up += max(0LL, a[i] - a[i - 1]);
    dn += max(0LL, a[i - 1] - a[i]);
  }
  cout << max(up, dn) << '\n' << abs(a[1] - a[n]) + 1 << '\n';
  return 0;
}
