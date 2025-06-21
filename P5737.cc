#include <bits/stdc++.h>
using namespace std;

inline bool isLeap(int year) {
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
int main() {
  int x, y, cnt = 0;
  vector<int> a;
  cin >> x >> y;
  for (int i = x; i <= y; i++) {
    if (isLeap(i)) {
      a.push_back(i);
      cnt++;
    }
  }
  cout << cnt << endl;
  for (auto x : a) cout << x << " ";
  cout << endl;
  return 0;
}
