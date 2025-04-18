#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define mod 1'000'000'007
#define maxn 1010
#define maxm 210
using namespace std;

int n, m, k, ans;
string a, b;
// f[x][i][j][l] ways a[:i] --> b[:j] w/ x substrs
// l=1 : substr include a[i-1]
// l=0 : all
int f[2][maxn][maxm][2];
int main() {
  cin >> n >> m >> k >> a >> b;
  f[0][0][0][1] = 1;
  for (int x = 0, i = 0, j = 0; i <= n; i++) f[x][i][j][0] = 1;
  for (int x = 1; x <= k; x++) {
    memset(f[x & 1], 0, sizeof(f[x & 1]));
    for (int j = 1; j <= m; j++) {
      for (int i = j; i <= n; i++) {
        if (a[i - 1] == b[j - 1]) {
          f[x & 1][i][j][1] =
              (f[x & 1][i - 1][j - 1][1] + f[x & 1 ^ 1][i - 1][j - 1][0]) % mod;
        }
        f[x & 1][i][j][0] = (f[x & 1][i - 1][j][0] + f[x & 1][i][j][1]) % mod;
      }
    }
  }
  cout << f[k & 1][n][m][0];
  return 0;
}
