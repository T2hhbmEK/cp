#include <bits/stdc++.h>
using namespace std;

bool IsPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return n >= 2;
}

void Goldbach(int n) {
  for (int i = 2, j = n - i; i <= j; i++, j--) {
    if (IsPrime(i) && IsPrime(j)) {
      cout << n << "=" << i << "+" << j << endl;
      return;
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 4; i <= n; i += 2) Goldbach(i);
  return 0;
}
