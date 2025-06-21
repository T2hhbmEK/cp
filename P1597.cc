#include <bits/stdc++.h>
using namespace std;
char x, y;
int a[128];
int main() {
  while (scanf("%c:=%c;", &x, &y) == 2) {
    if (isdigit(y)) {
      a[(int)x] = y - '0';
    } else {
      a[(int)x] = a[(int)y];
    }
  }
  printf("%d %d %d\n", a['a'], a['b'], a['c']);
  return 0;
}
