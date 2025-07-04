#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using isize = i64;
using vi = vector<i64>;
using vii = vector<vi>;
[[maybe_unused]] constexpr isize maxn = 1010;
using ai = array<i64, maxn>;
using aii = array<ai, maxn>;

#define fi first
#define se second
#define rep(i, a, b) for (isize i = (a); (i) <= (b); ++(i))
#define per(i, a, b) for (isize i = (a); (i) >= (b); --(i))
#define sz(x) (isize)(x).size()
#define all(x) (x).begin(), (x).end()
#define fastio() cin.tie(nullptr)->sync_with_stdio(false)
#define endl '\n'

struct Item {
  i64 val, ind;
};
isize n, m;
aii a;
deque<Item> q;
i64 cnt;

int main() {
  fastio();
  cin >> n >> m;
  rep(i, 1, n) rep(j, 1, m) {
    char c;
    cin >> c;
    a[i][j] = static_cast<i64>(c == '.');
    if (a[i][j] != 0) {
      a[i][j] += a[i - 1][j];
    }
  }
  // cerr << '\n';
  // rep(i, 1, n) rep(j, 1, m) cerr << a[i][j] << " \n"[j == m];
  // cerr << '\n';
  rep(i, 1, n) {
    q = {{.val = 0, .ind = 0}};
    // cerr << i << '\n';
    rep(j, 1, m + 1) {
      isize k = j;
      while (!q.empty() && q.back().val > a[i][j]) {
        // cerr << "q: ";
        // for (auto& [val, ind] : q) cerr << "{" << val << "," << ind << "} ";
        // cerr << '\n';
        auto& [val, ind] = q.back();
        q.pop_back();
        k = ind;
        i64 h = val - max(a[i][j], q.back().val);
        i64 w = j - k;
        i64 new_cnt = h * (w + 1) * w / 2;
        cnt += new_cnt;
        // cerr << k << ' ' << j << ' ' << h << ' ' << w << ' ' << new_cnt <<
        // '\n';
      }
      if (q.empty() || q.back().val < a[i][j]) {
        q.push_back({.val = a[i][j], .ind = k});
      }
    }
  }
  cout << cnt << '\n';
  return 0;
}
