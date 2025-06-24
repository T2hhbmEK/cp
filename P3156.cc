#include <iostream>
#include <vector>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  while (m--) {
    cin >> q;
    cout << a[q - 1] << '\n';
  }
  return 0;
}
