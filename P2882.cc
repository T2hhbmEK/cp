#include <cstring>
#include <iostream>
#define oo 0x3f3f3f3f
#define N 5010
using namespace std;

int n, a[N], b[N], kk, mm = oo;

void prt(int* a) {
  for (int i = 1; i <= n + 1; ++i) cerr << a[i];
  cerr << endl;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    char c;
    cin >> c;
    a[i] = c == 'B';
  }
  for (int i = n + 1; i >= 1; --i) a[i] ^= a[i - 1];
  for (int k = 1; k <= n; ++k) {
    int m = 0;
    // prt(a);
    memcpy(b, a, sizeof(a));
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
      if (b[i] && i + k <= n + 1) {
        b[i] ^= 1, b[i + k] ^= 1, ++m;
        // prt(b);
      }
      if (b[i]) {
        flag = false;
        break;
      }
    }
    // cerr << k << ' ' << m << ' ' << endl;
    if (flag && m < mm) mm = m, kk = k;
  }
  cout << kk << ' ' << mm << '\n';
  return 0;
}
