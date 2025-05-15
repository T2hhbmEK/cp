#include <bits/stdc++.h>
#define maxn 110
#define inf 0x3f3f3f3f
using namespace std;

int n, m;
char ch;
int a[maxn][maxn];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> ch;
      if (ch == '*') {
        a[i][j] = -inf;
        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            a[i + dx][j + dy]++;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] < 0) {
        cout << "*";
      } else {
        cout << a[i][j];
      }
    }
    cout << endl;
  }
  return 0;
}
