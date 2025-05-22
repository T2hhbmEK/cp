#include <bits/stdc++.h>
#define maxn 262145
#define maxv 59
using namespace std;

int n, a[maxn], ans;
int f[maxv][maxn];

inline int randint(int a, int b) {
  return rand() % (b - a) + a;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], f[a[i]][i] = i;
  ans = 1;
  for (int k = 2; k <= 58; k++) {
    for (int i = 1; i <= n; i++) {
      if (f[k - 1][i] > 1 && f[k - 1][f[k - 1][i] - 1] > 0) {
        f[k][i] = f[k - 1][f[k - 1][i] - 1];
      }
      if (f[k][i] > 0) ans = k;
    }
  }
  cout << ans << endl;
  return 0;
}
