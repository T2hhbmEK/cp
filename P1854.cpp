#include <bits/stdc++.h>
#define maxn 110
using namespace std;

int f, v, a[maxn][maxn];

int main() {
  cin >> f >> v;
  for (int i = 1; i <= f; i++) {
    for (int j = 1; j <= v; j++) {
      cin >> a[i][j];
    }
  }
  for (int k = 1; k <= f; k++) {
    for (int j = 1; j <= v; j++) {
      for (int i = j; i >= 1; i--) {
      }
    }
  }
  return 0;
}
