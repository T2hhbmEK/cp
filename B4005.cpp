#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] += a[i][j - 1];
    }
    for (int j = 1; j <= m; j++) {
      a[i][j] += a[i - 1][j];
    }
  }
  int ans = 0;
  for (int i1 = 1; i1 <= n; i1++) {
    for (int j1 = 1; j1 <= m; j1++) {
      for (int i2 = i1; i2 <= n; i2++) {
        for (int j2 = j1; j2 <= m; j2++) {
          int h = i2 - i1 + 1, w = j2 - j1 + 1;
          int area = h * w;
          int sum =
              a[i2][j2] - a[i1 - 1][j2] - a[i2][j1 - 1] + a[i1 - 1][j1 - 1];
          if (sum * 2 == area) ans = max(ans, area);
        }
      }
    }
  }
  cout << ans;
  return 0;
}