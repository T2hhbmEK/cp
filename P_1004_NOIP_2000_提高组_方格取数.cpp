#include <bits/stdc++.h>
#define maxn 30
using namespace std;

int n, a[maxn][maxn];

int main() {
  cin >> n;
  int x, y, z;
  while (cin >> x >> y >> z, x) {
    a[x][y] = z;
  }
  return 0;
}
