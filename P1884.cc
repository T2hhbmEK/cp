#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;
using i64 = long long;
using Vec2 = pair<int, int>;
using Rec = pair<Vec2, Vec2>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<Rec> a(n);
  set<int> xs, ys;
  for (auto& rec : a) {
    auto& [x1, y1] = rec.first;
    auto& [x2, y2] = rec.second;
    cin >> x1 >> y1 >> x2 >> y2;
    xs.insert(x1), ys.insert(y1), xs.insert(x2), ys.insert(y2);
  }
  vector<int> x(xs.begin(), xs.end()), y(ys.begin(), ys.end());
  vector<vector<int>> d(x.size(), vector<int>(y.size(), 0));
  for (auto& rec : a) {
    auto& [x1, y2] = rec.first;
    auto& [x2, y1] = rec.second;
    int i1 = lower_bound(x.begin(), x.end(), x1) - x.begin();
    int j1 = lower_bound(y.begin(), y.end(), y1) - y.begin();
    int i2 = lower_bound(x.begin(), x.end(), x2) - x.begin();
    int j2 = lower_bound(y.begin(), y.end(), y2) - y.begin();
    ++d[i2][j2], --d[i2][j1], --d[i1][j2], ++d[i1][j1];
  }
  i64 sum = 0;
  for (int i = 0; i < (int)x.size(); ++i) {
    for (int j = 0; j < (int)y.size(); ++j) {
      if (i > 0) d[i][j] += d[i - 1][j];
      if (j > 0) d[i][j] += d[i][j - 1];
      if (i > 0 && j > 0) d[i][j] -= d[i - 1][j - 1];
      // cerr << d[i][j] << " ";
      if (d[i][j] > 0) {
        sum += (i64)(x[i + 1] - x[i]) * (y[j + 1] - y[j]);
      }
    }
    // cerr << endl;
  }
  cout << sum << endl;
  return 0;
}
