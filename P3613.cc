#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<unordered_map<int, int>> a(n + 1);
  while (q--) {
    int op, i, j, k;
    cin >> op;
    if (op == 1) {
      cin >> i >> j >> k;
      a[i][j] = k;
    } else if (op == 2) {
      cin >> i >> j;
      cout << a[i][j] << '\n';
    }
  }
  return 0;
}
