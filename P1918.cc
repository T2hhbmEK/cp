#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> mp;
int n, q, m;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1, a; i <= n; i++) {
    cin >> a;
    mp[a] = i;
  }
  cin >> q;
  while (q--) {
    cin >> m;
    cout << mp[m] << '\n';
  }
  return 0;
}
