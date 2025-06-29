#include <algorithm>
#include <iostream>
using namespace std;

/*
 * (0 0)
 * (1 0) (1 1)
 * (2 0) (2 1) (2 2)
 * (i j) = (i-1 j-1) + (i-1 j)
 */

constexpr int maxn = 2e3;
int t, k;
int c[maxn + 10][maxn + 10];
void init() {
  c[0][0] = 1;
  for (int i = 1; i <= maxn; ++i) {
    for (int j = 0; j <= i; ++j) {
      c[i][j] = (j > 0 ? c[i - 1][j - 1] : 0) + c[i - 1][j];
      c[i][j] %= k;
    }
  }
  for (int i = 0; i <= maxn; ++i) {
    for (int j = 0; j <= i; ++j) {
      c[i][j] = c[i][j] == 0;
    }
  }
  for (int i = 0; i <= maxn; ++i) {
    for (int j = 0; j <= maxn; ++j) c[i][j] += j > 0 ? c[i][j - 1] : 0;
    for (int j = 0; j <= maxn; ++j) c[i][j] += i > 0 ? c[i - 1][j] : 0;
  }
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> t >> k;
  init();
  while (t--) {
    int n, m;
    cin >> n >> m;
    cout << c[n][m] << endl;
  }
  return 0;
}
