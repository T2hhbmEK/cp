#include <bits/stdc++.h>
#define maxn 1024
using namespace std;

int a[maxn][maxn];
void f(int n, int x, int y) {
  if (n == 1) {
    a[x][y] = 1;
    return;
  }
  n >>= 1;
  f(n, x, y + n);
  f(n, x + n, y);
  f(n, x + n, y + n);
}

int main() {
  int n;
  cin >> n;
  n = 1 << n;
  f(n, 0, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
