#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

[[maybe_unused]] constexpr auto inf = 0x3f3f3f3f;
[[maybe_unused]] constexpr auto nl = '\n';
[[maybe_unused]] constexpr auto maxn = 1010;

using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using isize = i64;
using pii = pair<i32, i32>;
using vi = vector<i32>;
using vii = vector<vi>;
using ai = array<i32, maxn>;
using aii = array<ai, maxn>;

#define fi first
#define se second
#define rep(i, a, b) for (i32 i = (a); (i) <= (b); ++(i))
#define per(i, a, b) for (i32 i = (a); (i) >= (b); --(i))
#define sz(x) static_cast<i32>((x).size())
#define all(x) (x).begin(), (x).end()
#define fastio() cin.tie(nullptr)->sync_with_stdio(false)

i32 a, b, n;
aii arr, amin, amax;

void work(aii &dst, const function<bool(i32, i32)> &lt) {
  auto le = [&lt](i32 u, i32 v) { return !lt(v, u); };
  aii tmp;
  for (auto &x : tmp) x.fill(0);
  rep(i, 1, a) {
    deque<i32> q;
    rep(j, 1, b) {
      while (!q.empty() && q.front() <= j - n) q.pop_front();
      while (!q.empty() && le(arr[i][j], arr[i][q.back()])) q.pop_back();
      q.push_back(j);
      tmp[i][j] = arr[i][q.front()];
    }
  }
  rep(j, 1, b) {
    deque<i32> q;
    rep(i, 1, a) {
      while (!q.empty() && q.front() <= i - n) q.pop_front();
      while (!q.empty() && le(tmp[i][j], tmp[q.back()][j])) q.pop_back();
      q.push_back(i);
      dst[i][j] = tmp[q.front()][j];
    }
  }
}

int main() {
  fastio();
  cin >> a >> b >> n;
  rep(i, 1, a) rep(j, 1, b) { cin >> arr[i][j]; }
  work(amin, less<i32>{});
  work(amax, greater<i32>{});
  i32 ans = inf;
  rep(i, n, a) rep(j, n, b) ans = min(ans, amax[i][j] - amin[i][j]);
  cout << ans << nl;
  return 0;
}
