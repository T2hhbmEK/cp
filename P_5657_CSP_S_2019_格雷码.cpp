#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int n, k;

void f(int n, int k) {
  if (n == 1) {
    cout << k;
    return;
  }
  int n2 = 1ull << (n - 1);
  if (k < n2) {
    cout << 0;
    f(n - 1, k);
  } else {
    cout << 1;
    f(n - 1, n2 - 1 - (k - n2));
  }
}

signed main() {
  cin >> n >> k;
  f(n, k);
  return 0;
}
