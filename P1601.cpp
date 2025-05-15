#include <bits/stdc++.h>
#define maxn 510
using namespace std;

int a[maxn], na, b[maxn], nb;

void read(int a[], int &na) {
  string s;
  cin >> s;
  for (int i = s.size() - 1; i >= 0; i--) {
    a[na++] = s[i] & 0xF;
  }
}

int main() {
  read(a, na);
  read(b, nb);
  for (int i = 0; i < na || i < nb; i++) {
    a[i] += b[i];
    a[i + 1] += a[i] / 10;
    a[i] %= 10;
  }
  bool leading_zeros = 1;
  for (int i = max(na, nb); i >= 0; i--) {
    if (a[i] != 0) leading_zeros = 0;
    if (leading_zeros) continue;
    cout << a[i];
  }
  if (leading_zeros) cout << 0;
  cout << endl;
  return 0;
}
