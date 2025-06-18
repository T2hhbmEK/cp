#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define inf 0x3f3f3f3f
using namespace std;
bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return n >= 2;
}
int main() {
  string s;
  vector<int> counter(128, 0);
  cin >> s;
  for (auto ch : s) {
    counter[ch]++;
  }
  int mx = 0, mn = inf;
  for (auto x : counter) {
    if (x != 0) {
      mx = max(mx, x);
      mn = min(mn, x);
    }
  }
  int diff = mx - mn;
  if (isPrime(diff)) {
    cout << "Lucky Word" << endl << diff << endl;
  } else {
    cout << "No Answer" << endl << 0 << endl;
  }
  return 0;
}
