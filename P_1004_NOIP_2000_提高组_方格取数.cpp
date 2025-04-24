#include <bits/stdc++.h>
#define maxn 30
using namespace std;

int n, a[maxn][maxn];
int f[maxn][maxn][maxn];

inline bool chk(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= n;
}

int main() {
  cin >> n;
  for (int x, y, z; cin >> x >> y >> z, x;) a[x][y] = z;
  // z = x + y
  f[2][1][1] = a[1][1];
  for (int z = 1 + 2; z <= n + n; z++) {
    for (int x1 = 1; x1 < z; x1++) {
      for (int x2 = x1; x2 < z; x2++) {
        int y1 = z - x1, y2 = z - x2;
        if (chk(x1, y1) && chk(x2, y2)) {
          for (int x1p : {x1 - 1, x1}) {
            for (int x2p : {x2 - 1, x2}) {
              f[z][x1][x2] = max(f[z][x1][x2], f[z - 1][x1p][x2p]);
            }
          }
          f[z][x1][x2] += a[x1][y1];
          if (x1 != x2) f[z][x1][x2] += a[x2][y2];
          // printf("%d %d %d %d %d\n", x1, y1, x2, y2, f[z][x1][y1]);
        }
      }
    }
  }
  cout << f[n + n][n][n];
  return 0;
}
