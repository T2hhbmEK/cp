#include <bits/stdc++.h>
using namespace std;

int n, x, y;

int main() {
  cin >> n >> x >> y;
  n -= (y + x - 1) / x;
  cout << n;
  return 0;
}
