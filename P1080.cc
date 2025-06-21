#include <bits/stdc++.h>

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <ostream>
#define inf 0x3f3f3f3f
#define maxn 1010
#define mod 10000
#define ratio 4
using namespace std;
struct Bigint {
  int a[maxn], n;
  Bigint(int x) {
    memset(a, 0, sizeof(a));
    n = 0;
    while (x) {
      a[++n] = x % mod;
      x /= mod;
    }
  }
  Bigint(const Bigint& x) { *this = x; }
  Bigint& operator=(const Bigint& x) {
    if (this == &x) return *this;
    memcpy(a, x.a, sizeof(a));
    n = x.n;
    return *this;
  }
  Bigint& flatten() {
    for (int i = 1; i <= n; i++) {
      a[i + 1] += a[i] / mod;
      a[i] %= mod;
      if (a[i + 1] > 0) n = max(n, i + 1);
    }
    while (n > 0 && a[n] == 0) --n;
    return *this;
  }
};
bool operator<(const Bigint& x, const Bigint& y) {
  if (x.n != y.n) return x.n < y.n;
  for (int i = x.n; i >= 1; --i) {
    if (x.a[i] != y.a[i]) {
      return x.a[i] < y.a[i];
    }
  }
  return false;
}
ostream& operator<<(ostream& cout, Bigint& x) {
  cout << x.a[x.n];
  for (int i = x.n - 1; i >= 1; --i) {
    cout << setfill('0') << setw(ratio) << x.a[i];
  }
  return cout;
}
Bigint& operator*=(Bigint& x, int y) {
  for (int i = 1; i <= x.n; i++) x.a[i] *= y;
  return x.flatten();
}
Bigint& operator/=(Bigint& x, int y) {
  for (int i = x.n; i >= 1; i--) {
    x.a[i - 1] += x.a[i] % y * mod;
    x.a[i] /= y;
  }
  x.a[0] = 0;
  return x.flatten();
}
Bigint operator/(Bigint& x, int y) {
  Bigint z(x);
  z /= y;
  return z;
}
struct Hand {
  int a, b, prod;
} s[maxn];
int n;
Bigint ans(0);
int main() {
  cin >> n;
  for (int i = 0; i <= n; ++i) cin >> s[i].a >> s[i].b;
  for (int i = 0; i <= n; ++i) s[i].prod = s[i].a * s[i].b;
  sort(s + 1, s + 1 + n, [](auto& x, auto& y) { return x.prod < y.prod; });
  Bigint pre(s[0].a);
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, pre / s[i].b);
    pre *= s[i].a;
  }
  cout << ans << endl;
  return 0;
}
