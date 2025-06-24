#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  ll lo = *max_element(all(a)), hi = accumulate(all(a), 0LL, plus<ll>());
  while (lo < hi) {
    ll mid = lo + (hi - lo) / 2;
    int cnt = 1;
    ll sum = 0;
    for (int x : a) {
      sum += x;
      if (sum > mid) ++cnt, sum = x;
    }
    if (cnt <= m) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << endl;
  return 0;
}
