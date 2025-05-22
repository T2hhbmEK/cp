#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
bool f() {
  string a, b;
  cin >> a >> b;
  if (a.size() < b.size()) swap(a, b);
  int L = 0, R1 = a.size() - 1, R2 = b.size() - 1;
  while (a[L] == b[L]) L++;
  while (a[R1] == b[R2]) R1--, R2--;
  return L >= R1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    if (f()) {
      cout << "similar" << endl;
    } else {
      cout << "not similar" << endl;
    }
  }
  return 0;
}