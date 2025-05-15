#include <bits/stdc++.h>
using namespace std;

int n, a;

int main() {
  cin >> n;
  while (n--) {
    cin >> a;
    int x = a % 10;
    if (x < 5) {
      cout << a - x << '\n';
    } else {
      cout << a - x + 10 << '\n';
    }
  }
  return 0;
}
