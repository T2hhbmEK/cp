#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
constexpr int inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, ans = -inf;
  cin >> n;
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      ans = max(ans, a[i][j]);
      a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
    }
  }
  for (int t = 1; t <= n; ++t) {
    for (int l = 1; l <= n; ++l) {
      for (int b = t; b <= n; ++b) {
        for (int r = l; r <= n; ++r) {
          int sum = a[b][r] - a[t - 1][r] - a[b][l - 1] + a[t - 1][l - 1];
          ans = max(ans, sum);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
