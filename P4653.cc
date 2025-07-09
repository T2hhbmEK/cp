#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 100010;
double a[maxn], b[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  sort(a + 1, a + 1 + n, greater<>());
  sort(b + 1, b + 1 + n, greater<>());
  for (int i = 1; i <= n; ++i) a[i] += a[i - 1], b[i] += b[i - 1];
  double suma = 0, sumb = 0, ans = 0;
  for (int i = 1, j = 1; i <= n && j <= n; suma < sumb ? ++i : ++j) {
    suma = a[i] - i - j;
    sumb = b[j] - i - j;
    ans = max(ans, min(suma, sumb));
  }
  cout << fixed << setprecision(4) << ans << '\n';
  return 0;
}
