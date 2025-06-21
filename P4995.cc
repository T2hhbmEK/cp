#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define maxn 310
using namespace std;
int n, h[maxn];
ll ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> h[i];
  sort(h + 1, h + 1 + n);
  for (int i = 0, j = n, up = 1; i <= j;) {
    ans += (h[i] - h[j]) * (h[i] - h[j]);
    if (up == 1) {
      ++i;
    } else {
      --j;
    }
    up ^= 1;
  }
  cout << ans << endl;
  return 0;
}
