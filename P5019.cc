#include <bits/stdc++.h>
#define maxn 100'010
using namespace std;

int n, a[maxn], ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    ans += max(0, a[i] - a[i - 1]);
  }
  cout << ans << endl;
  return 0;
}
