#include <bits/stdc++.h>
#define MAXN 110
using namespace std;
int n, m, a[MAXN], sum;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sum = accumulate(a + 1, a + 1 + n, 0);
  if (sum <= m) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
