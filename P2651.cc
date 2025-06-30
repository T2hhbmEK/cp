#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    swap(a[0], a[1]);
    for (int i = 1; i < n && a[0] > 1; ++i) {
      int g = gcd(a[0], a[i]);
      a[0] /= g, a[i] /= g;
    }
    cout << (a[0] == 1 ? "Yes" : "No") << '\n';
  }
  return 0;
}
