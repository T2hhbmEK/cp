#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int n;
int a[maxn];
int f[40];
int ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  // O(nlogn)
  for (int i = 1; i <= n; i++) {
    int ma = 0;
    for (int j = 0; j < 30; j++) {
      if ((a[i] >> j) & 1) {
        ma = max(ma, f[j] + 1);
      }
    }
    for (int j = 0; j < 30; j++) {
      if ((a[i] >> j) & 1) {
        f[j] = max(f[j], ma);
      }
    }
  }
  for (int j = 0; j < 30; j++) {
    ans = max(ans, f[j]);
  }
  cout << ans << endl;
  return 0;
}
