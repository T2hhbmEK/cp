#include <bits/stdc++.h>
using namespace std;
int a, b, x, y;
int solve() {
  cin >> a >> b >> x >> y;
  if (b == a) return 0;
  if (b < a) {
    if ((b ^ 1) == a) return y;
    return -1;
  }
  if (y > x) return (b - a) * x;
  int sum = 0;
  for (int i = a; i < b; ++i) sum += (i & 1) ? x : y;
  return sum;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }
  return 0;
}
