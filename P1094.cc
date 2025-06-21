#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 30010
using namespace std;
int w, n, p[maxn], cnt;
int main() {
  cin >> w >> n;
  for (int i = 1; i <= n; i++) cin >> p[i];
  sort(p + 1, p + 1 + n);
  for (int i = 1, j = n; i <= j; --j) {
    if (i < j && p[i] + p[j] <= w) ++i;
    ++cnt;
  }
  cout << cnt << endl;
  return 0;
}
