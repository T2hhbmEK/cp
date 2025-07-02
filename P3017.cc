#include <iostream>
#include <vector>
#define maxn 510
#define sz(x) (int)(x).size()
#define vi vector<int>
#define vii vector<vi>
using namespace std;

int r, c, a, b, n[maxn][maxn];

bool chk(int m) {
  vi x = {0};
  for (int i = 1; i <= r; ++i) {
    vi y = {0};
    for (int j = 1; j <= r; ++j) {
      int s = n[i][j] - n[x.back()][j] - n[i][y.back()] + n[x.back()][y.back()];
      if (s >= m) y.push_back(j);
    }
    if (sz(y) >= b + 1) x.push_back(i);
  }
  return sz(x) >= a + 1;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> r >> c >> a >> b;
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      cin >> n[i][j];
      n[i][j] += n[i - 1][j] + n[i][j - 1] - n[i - 1][j - 1];
    }
  }
  int lo = 0, hi = n[r][c] / a / b;
  while (lo < hi) {
    int mi = lo + (hi - lo + 1) / 2;
    if (chk(mi)) {
      lo = mi;
    } else {
      hi = mi - 1;
    }
  }
  cout << lo << endl;
  return 0;
}
