#include <iostream>
#define ll long long
#define maxn 1010
#define inf 0x3f3f3f3f3f3f3f3fLL
using namespace std;

ll a[maxn][maxn];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, c;
  cin >> n >> m >> c;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }
  ll mx = -inf;
  int x, y;
  for (int i = 1; i + c - 1 <= n; ++i) {
    for (int j = 1; j + c - 1 <= m; ++j) {
      // cerr << i << " " << j << endl;
      ll sum = a[i + c - 1][j + c - 1] - a[i - 1][j + c - 1] -
               a[i + c - 1][j - 1] + a[i - 1][j - 1];
      if (sum > mx) {
        mx = sum;
        x = i;
        y = j;
      }
    }
  }
  cout << x << ' ' << y << '\n';
  return 0;
}
