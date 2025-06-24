#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
using namespace std;
int main() {
  int n, x, sum = 0;
  cin >> n;
  set<int> a;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    int mi = numeric_limits<int>::max();
    if (a.empty()) {
      mi = x;
    } else {
      auto it = a.lower_bound(x);
      if (it != a.end()) mi = min(mi, *it - x);
      if (it != a.begin()) mi = min(mi, x - *(--it));
    }
    sum += mi;
    a.insert(x);
  }
  cout << sum << endl;
  return 0;
}
