#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  int a = 0, x;
  while (n--) cin >> x, a ^= x;
  cout << a << endl;
  return 0;
}
