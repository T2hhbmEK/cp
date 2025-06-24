#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
using namespace std;
int m, op, x;
set<int> s;
int main() {
  cin >> m;
  while (m--) {
    cin >> op >> x;
    if (op == 1) {
      if (s.find(x) != s.end()) {
        cout << "Already Exist" << endl;
      } else {
        s.insert(x);
      }
    } else {
      auto p = s.find(x);
      if (p != s.end()) {
        s.erase(p);
        cout << x << endl;
      } else {
        if (s.empty()) {
          cout << "Empty" << endl;
        } else {
          p = s.lower_bound(x);
          if (p != s.begin()) {
            if (p == s.end() || x - *prev(p) <= *p - x) --p;
          }
          cout << *p << endl;
          s.erase(p);
        }
      }
    }
  }
  return 0;
}
