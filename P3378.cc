#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;
int a[MAXN], m, n;
int op, x;
void insert(int x) {
  a[++m] = x;
  for (int i = m; i >> 1 > 0; i >>= 1) {
    if (a[i] < a[i >> 1]) swap(a[i], a[i >> 1]);
  }
}
void pop() {
  a[1] = a[m--];
  int i = 1;
  while (i << 1 <= m) {
    int j = i << 1;
    if (a[i] <= a[j] && a[i] <= a[j + 1]) break;
    int x = j + 1 <= m && a[j] > a[j + 1];
    swap(a[i], a[j + x]);
    i = j + x;
  }
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n;
  while (n--) {
    cin >> op;
    if (op == 1) {
      cin >> x;
      insert(x);
    } else if (op == 2) {
      cout << a[1] << '\n';
    } else {
      pop();
    }
  }
  return 0;
}
