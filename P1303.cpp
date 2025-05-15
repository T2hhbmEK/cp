#include <bits/stdc++.h>
#define maxn 4010
using namespace std;

struct Bigint {
  int a[maxn], n;
  Bigint(int x = 0) {
    n = 0, memset(a, 0, sizeof(a));
    while (x) {
      a[++n] = x % 10;
      x /= 10;
    }
  }
  int& operator[](int i) {
    return a[i];
  }
  void get() {
    n = 0, memset(a, 0, sizeof(a));
    char c;
    c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {
      a[++n] = c & 0xF;
      c = getchar();
    }
    for (int i = 1, j = n; i < j; i++, j--) swap(a[i], a[j]);
  }
  void put() {
    if (n == 0) putchar('0');
    for (int i = n; i >= 1; i--) {
      putchar('0' | a[i]);
    }
  }
  void flatten() {
    for (int i = 1; i < n; i++) {
      a[i + 1] += a[i] / 10;
      a[i] %= 10;
      if (a[n + 1]) n++;
    }
    while (n >= 1 && a[n] == 0) n--;
  }
} a, b;

Bigint operator*(Bigint& a, Bigint& b) {
  Bigint c;
  c.n = a.n + b.n;
  for (int i = 1; i <= a.n; i++) {
    for (int j = 1; j <= b.n; j++) {
      c[i + j - 1] += a[i] * b[j];
    }
  }
  c.flatten();
  return c;
}

int main() {
  a.get(), b.get();
  (a * b).put();
  return 0;
}
