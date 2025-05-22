#include <bits/stdc++.h>
#define maxn 110
using namespace std;

int n, m, a[maxn][maxn];
int f[maxn][maxn][maxn];
// g[k][i][j]: last flower pos in [i,j]
int g[maxn][maxn][maxn];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  memset(f, -0x3f, sizeof(f));
  memset(f[0], 0, sizeof(f[0]));
  for (int k = 1; k <= n; k++) {
    for (int j = 1; j <= m; j++) {
      for (int i = j; i >= 1; i--) {
        int x = f[k - 1][i][j - 1] + a[k][j];
        int y = f[k][i][j - 1];
        if (x >= y) {
          f[k][i][j] = x;
          g[k][i][j] = j;
        } else {
          f[k][i][j] = y;
          g[k][i][j] = g[k][i][j - 1];
        }
      }
    }
  }
  cout << f[n][1][m] << endl;
  stack<int> s;
  for (int i = n, x = g[i][1][m]; i >= 1;
       --i, x = g[i][1][x - 1]) {
    s.push(x);
  }
  // int sum = 0, i = 1;
  while (!s.empty()) {
    // sum += a[i++][s.top()];
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  // cout << sum << endl;
  return 0;
}
