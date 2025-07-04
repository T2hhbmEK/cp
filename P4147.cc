#include <algorithm>
#include <cstdio>
#define maxn 1010
using namespace std;
int n, m, ans;
int a[maxn][maxn], dn[maxn][maxn], up[maxn][maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c;
      scanf(" %c", &c);
      a[i][j] = (c == 'F');
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) up[i][j] = up[i - 1][j] + 1;
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) dn[i][j] = dn[i + 1][j] + 1;
    }
  }
  // fprintf(stderr, "up:\n");
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     fprintf(stderr, "%d ", up[i][j]);
  //   }
  //   putchar('\n');
  // }
  // fprintf(stderr, "dn:\n");
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     fprintf(stderr, "%d ", dn[i][j]);
  //   }
  //   putchar('\n');
  // }
  for (int i = 1; i <= n; ++i) {
    int min_up = 0;
    int min_dn = 0;
    int min_lf = 0;
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) {
        if (!a[i][j - 1]) {
          min_lf = j;
          min_up = up[i][j];
          min_dn = dn[i][j];
        } else {
          min_up = min(min_up, up[i][j]);
          min_dn = min(min_dn, dn[i][j]);
        }
        int w = j - min_lf + 1, h = min_up + min_dn - 1;
        // fprintf(stderr, "%d %d %d %d\n", i, j, w, h);
        ans = max(ans, w * h);
      } else {
        min_up = min_dn = 0;
      }
    }
  }
  printf("%d\n", ans * 3);
  return 0;
}
