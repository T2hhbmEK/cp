#include <algorithm>
#include <iostream>
#define maxn 100010
using namespace std;
int n, cnt[maxn];
struct Item {
  int x, id, rk;
} a[maxn];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].x, a[i].id = i;
  sort(a + 1, a + 1 + n, [](auto& u, auto& v) {
    if (u.x != v.x) return u.x < v.x;
    return u.id < v.id;
  });
  for (int i = 1; i <= n; ++i) a[i].rk = i;
  // sort(a + 1, a + 1 + n, [](auto& u, auto& v) { return u.id < v.id; });
  for (int i = 1; i <= n; ++i) {
    if (a[i].rk > a[i].id) cnt[a[i].id]++, cnt[a[i].rk]--;
  }
  for (int i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
  int ans = *max_element(cnt + 1, cnt + 1 + n);
  cout << max(1, ans) << endl;
  return 0;
}
