#include <bits/stdc++.h>
#define kMaxN 1010
using namespace std;

struct Student {
  int i, a, b;
  int get_s() { return a * 7 + b * 3; }
  int get_tot() { return a + b; }
  bool Is_Excellent() { return get_tot() > 140 && get_s() >= 800; }
};

istream& operator>>(istream& is, Student& x) { return is >> x.i >> x.a >> x.b; }

int main() {
  int n;
  cin >> n;
  vector<Student> a(n);
  for (auto& x : a) cin >> x;
  for (auto& x : a) {
    if (x.Is_Excellent()) {
      cout << "Excellent" << endl;
    } else {
      cout << "Not excellent" << endl;
    }
  }
  return 0;
}
