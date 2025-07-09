#include <algorithm>
#include <cstdio>
#define MAXN 5010
using namespace std;
struct Point {
  int x, y;
};
int n, m, k, ans;
Point a[MAXN];
void work() {
  for (int i = 1; i <= k; ++i) {
    int yL = 0, yR = m;
    for (int j = i + 1; j <= k; ++j) {
      if (a[j].x == a[i].x) continue;
      ans = max(ans, (yR - yL) * abs(a[j].x - a[i].x));
      // fprintf(stderr, "i: %d %d j: %d %d\n", a[i].x, a[i].y, a[j].x, a[j].y);
      // fprintf(stderr, "%d\n", ans);
      if (a[j].y == a[i].y) break;
      if (a[j].y < a[i].y) {
        yL = max(yL, a[j].y);
      } else {  // >
        yR = min(yR, a[j].y);
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) scanf("%d%d", &a[i].x, &a[i].y);
  for (int i : {0, n}) {
    for (int j : {0, m}) {
      a[++k] = {i, j};
    }
  }
  sort(a + 1, a + 1 + k, [](auto u, auto v) {
    if (u.x != v.x) return u.x < v.x;
    return u.y < v.y;
  });
  work();
  for (int i = 1, j = k; i < j; ++i, --j) swap(a[i], a[j]);
  work();
  sort(a + 1, a + 1 + k, [](auto u, auto v) {
    if (u.y != v.y) return u.y < v.y;
    return u.x < v.x;
  });
  for (int i = 2; i <= k; ++i) {
    ans = max(ans, n * (a[i].y - a[i - 1].y));
    // fprintf(stderr, "%d\n", ans);
  }
  printf("%d\n", ans);
  return 0;
}
