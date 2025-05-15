#include <bits/stdc++.h>
using namespace std;

string s, t;
int a, b, cnt;

inline void show(int a, int b) {
  cout << a << ":" << b << endl;
}

void f(int m = 11) {
  a = b = cnt = 0;
  for (char c : s) {
    if (c == 'E') break;
    if (c == 'W') {
      a++;
    } else if (c == 'L') {
      b++;
    }
    if (abs(a - b) >= 2 && max(a, b) >= m) {
      show(a, b);
      cnt++;
      a = b = 0;
    }
  }
  show(a, b);
}

int main() {
  while (cin >> t) {
    s += t;
  }
  f(11);
  cout << endl;
  f(21);
  return 0;
}
