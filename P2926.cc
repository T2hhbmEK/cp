#include <iostream>
#include <unordered_set>
using namespace std;

constexpr int maxn = 1e6 + 5;
unordered_set<int> mp[maxn];
int n, a[maxn];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mp[a[i]].insert(i);
  }
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = 1; j * j <= a[i]; ++j) {
      if (a[i] % j == 0) {
        for (auto x : unordered_set<int>({j, a[i] / j})) {
          cnt += mp[x].size();
          if (mp[x].contains(i)) --cnt;
        }
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
