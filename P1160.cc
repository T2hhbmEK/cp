#include <cstring>
#include <iostream>
#define maxn 100010
using namespace std;
struct Node {
  int pre, nex;
} a[maxn];
int n, k, p, u, v, q, x;
int main() {
  memset(a, -1, sizeof(a));
  cin >> n;
  a[0].pre = a[0].nex = 1;
  a[1].pre = a[1].nex = 0;
  for (int i = 2; i <= n; i++) {
    cin >> k >> p;
    if (p == 0) {
      u = a[k].pre, v = k;
    } else {
      u = k, v = a[k].nex;
    }
    a[u].nex = i, a[v].pre = i;
    a[i].pre = u, a[i].nex = v;
  }
  cin >> q;
  while (q--) {
    cin >> x;
    int u = a[x].pre, v = a[x].nex;
    if (u == -1 || v == -1) continue;
    a[u].nex = v;
    a[v].pre = u;
    a[x].pre = a[x].nex = -1;
  }
  for (int i = a[0].nex; i != 0; i = a[i].nex) {
    cout << i << ' ';
  }
  cout << '\n';
  return 0;
}
