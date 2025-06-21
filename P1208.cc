#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 2000000
using namespace std;
int n, m, ans;
pair<int, int> pa[maxn];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> pa[i].first >> pa[i].second;
  }
  sort(pa + 1, pa + 1 + m);
  for (int i = 1; i <= m && n > 0; ++i) {
    int a = min(n, pa[i].second);
    ans += pa[i].first * a;
    n -= a;
  }
  assert(n == 0);
  cout << ans << endl;
  return 0;
}
