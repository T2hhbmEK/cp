#include <algorithm>
#include <iostream>
#define maxn 10010
using namespace std;
int a[maxn];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  for (int L, H, R; cin >> L >> H >> R;) {
    for (int i = L; i < R; ++i) a[i] = max(a[i], H);
  }
  for (int i = 1; i < maxn; ++i) {
    if (a[i] != a[i - 1]) cout << i << ' ' << a[i] << ' ';
  }
  cout << endl;
  return 0;
}
