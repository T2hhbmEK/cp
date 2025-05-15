#include <bits/stdc++.h>
#define maxn 510
#define fi first
#define se second
using namespace std;
int n, m;
int a[maxn][maxn];
int x, y, r, z;

void rot(int &u, int &v) {
  u -= x, v -= y;
  swap(u, v);
  if (z) {
    u = -u;
  } else {
    v = -v;
  }
  u += x, v += y;
}

inline bool chk(int u, int v) {
  return u >= 1 && u <= n && v >= 1 && v <= n;
}

int main() {
  cin >> n >> m;
  for (int i = 1, k = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = k++;
    }
  }
  while (m--) {
    cin >> x >> y >> r >> z;
    for (int i = x; i <= x + r; i++) {
      for (int j = y + 1; j <= y + r; j++) {
        int u = i, v = j;
        rot(u, v), swap(a[i][j], a[u][v]);
        rot(u, v), swap(a[i][j], a[u][v]);
        rot(u, v), swap(a[i][j], a[u][v]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << a[i][j] << " \n"[j == n];
    }
  }
  return 0;
}
