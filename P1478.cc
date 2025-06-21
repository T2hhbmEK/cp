#include <bits/stdc++.h>
using namespace std;
#define kMaxN 5005
struct Apple {
  int x, y;
} xy[kMaxN];
int n, s, a, b, cnt;
int main() {
  scanf("%d%d", &n, &s);
  scanf("%d%d", &a, &b);
  for (int i = 1; i <= n; i++) scanf("%d%d", &xy[i].x, &xy[i].y);
  sort(xy + 1, xy + 1 + n, [](auto& i, auto& j) { return i.y < j.y; });
  for (int i = 1; i <= n && xy[i].y <= s; i++) {
    if (xy[i].x <= a + b) {
      s -= xy[i].y;
      cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
