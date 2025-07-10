#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 200010
#define LOGN 20
using namespace std;
int n, m;
int a[MAXN][LOGN], log2i[MAXN];
void init() {
  for (int i = 2; i <= m; ++i) {
    log2i[i] = log2i[i >> 1] + 1;
  }
  memset(a, INF, sizeof(a));
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> m >> n;
  // m = rand() % 20 + 1;
  // n = rand() % 5 + 1;
  init();
  for (int i = 1; i <= m; ++i) cin >> a[i][0];
  // srand(time(nullptr));
  // for (int i = 1; i <= m; ++i) a[i][0] = rand() % m + 1;
  // for (int i = 1; i <= m; ++i) cerr << i << ' ';
  // cerr << '\n';
  // for (int i = 1; i <= m; ++i) cerr << a[i][0] << ' ';
  // cerr << '\n';
  for (int j = 1; j <= log2i[m]; ++j) {
    int d = 1 << (j - 1);
    for (int i = 1; i <= m; ++i) {
      a[i][j] = min(a[i][j - 1], a[i + d][j - 1]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    int l, r;
    cin >> l >> r;
    // l = rand() % m + 1;
    // r = l + rand() % (m - l + 1);
    // cerr << l << ' ' << r << '\n';
    int j = log2i[r - l + 1];
    cout << min(a[l][j], a[r - (1 << j) + 1][j]) << " ";
  }
  cout << "\n";
  return 0;
}
