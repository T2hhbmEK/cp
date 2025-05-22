#include <bits/stdc++.h>
#define maxn 355
#define maxm 125
using namespace std;

int n, m, a[maxn], b[maxm];

int f[41][41][41][41], cnt[5];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i], cnt[b[i]]++;
  f[0][0][0][0] = a[1];
  for (int i = 0; i <= cnt[1]; i++) {
    for (int j = 0; j <= cnt[2]; j++) {
      for (int k = 0; k <= cnt[3]; k++) {
        for (int l = 0; l <= cnt[4]; l++) {
          int s = 1 + i * 1 + j * 2 + k * 3 + l * 4;
          if (i >= 1) {
            f[i][j][k][l] = max(f[i][j][k][l], f[i - 1][j][k][l] + a[s]);
          }
          if (j >= 1) {
            f[i][j][k][l] = max(f[i][j][k][l], f[i][j - 1][k][l] + a[s]);
          }
          if (k >= 1) {
            f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k - 1][l] + a[s]);
          }
          if (l >= 1) {
            f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k][l - 1] + a[s]);
          }
          // printf("%d %d %d %d %d \n", i, j, k, l, f[i][j][k][l]);
        }
      }
    }
  }
  cout << f[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
  return 0;
}
