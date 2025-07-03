#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define oo 0x3f3f3f3f
#define maxn 50010
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  unordered_set<int> IDs;
  for (auto& [x, ID] : a) {
    cin >> x >> ID;
    IDs.insert(ID);
  }
  unordered_map<int, int> IDmp;
  sort(all(a));
  int ans = oo;
  for (int i = 0, j = 0; j < n; ++j) {
    ++IDmp[a[j].second];
    if (sz(IDmp) < sz(IDs)) continue;
    while (IDmp[a[i].second] > 1) {
      --IDmp[a[i].second];
      ++i;
    }
    ans = min(ans, a[j].first - a[i].first);
  }
  cout << ans << endl;
  return 0;
}
