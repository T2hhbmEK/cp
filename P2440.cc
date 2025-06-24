#include <algorithm>
#include <iostream>
#include <vector>
#define all(a) (a).begin(), (a).end()
using namespace std;
using vi = vector<int>;
using ll = long long;
int main() {
  int n, k;
  cin >> n >> k;
  vi L(n);
  for (auto &x : L) cin >> x;
  int lo = 1, hi = *max_element(all(L)), ans = 0;
  while (lo <= hi) {
    int mi = (lo + hi + 1) / 2;
    ll sum = 0;
    for (auto x : L) sum += x / mi;
    if (sum >= k) {
      ans = mi;
      lo = mi + 1;
    } else {
      hi = mi - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
