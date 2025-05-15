#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int a, p;

int anmodp(int n) {
  int s = 1, f = a;
  for (int i = 0; (1 << i) <= n; i++) {
    if ((1 << i) & n) {
      (s *= f) %= p;
    }
    (f *= f) %= p;
  }
  return s;
}

bool solve() {
  cin >> a >> p;
  int n = p - 1;
  if (anmodp(n) != 1) {
    return 0;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      // cout << i << " " << n / i << endl;
      if (anmodp(i) == 1 || anmodp(n / i) == 1) return 0;
    }
  }
  return 1;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    if (solve()) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }
  return 0;
}
