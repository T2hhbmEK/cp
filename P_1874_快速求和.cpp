#include <bits/stdc++.h>
using namespace std;

const int inf = 1e5 + 7;
const int maxv = 1e5 + 10;
const int maxn = 45;
string s;
int t, n;
int f[maxv][maxn];  // f[k][i] substr [0,i], sum=k, min no. of +
int g[maxn][maxn];  // g[i][j] substr [i,j], val

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> s >> t;
  n = s.size();
  memset(f, 0x3f, sizeof(f));
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      g[i][j] = min(inf, g[i][j - 1] * 10 + (s[j] - '0'));
    }
  }
  for (int i = 0; i < n; i++) {
    f[g[0][i]][i] = 0;
  }
  for (int k = 1; k <= t; k++) {     // target
    for (int i = 0; i < n; i++) {    // [0,i]
      for (int j = i; j > 0; j--) {  // last + before j
        if (g[j][i] > k) break;
        f[k][i] = min({inf, f[k][i], f[k - g[j][i]][j - 1] + 1});
      }
    }
  }
  // for (int i = 0; i < n; i++) cout << f[t][i] << " ";
  int ans = f[t][n - 1];
  if (ans >= inf) ans = -1;
  cout << ans << endl;
  return 0;
}
