#include <bits/stdc++.h>
using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using f32 = float;
using f64 = double;
using isize = i64;

template <typename T>
constexpr i32 sz(const T& x) {
  return static_cast<i32>(x.size());
}
inline void fastio() {
  constexpr auto min_ver = 202002L;
  static_assert(__cplusplus >= min_ver, "Minimal C++ standard: C++20");
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
}

[[maybe_unused]] constexpr i32 inf = 0x3f3f3f3f;
[[maybe_unused]] constexpr char nl = '\n';
[[maybe_unused]] constexpr i32 maxn = 100010;

void bruteforce(auto& s) {
  f64 ans = 0;
  for (i32 i : views::iota(0, 1 << (2 * sz(s)))) {
    f64 sum_a = 0, sum_b = 0;
    ostringstream buf;
    for (i32 j : views::iota(0, (2 * sz(s)))) {
      if (i >> j & 1) {
        if (j % 2 == 0) {
          buf << (j >> 1) + 1 << "a ";
          sum_a += s[j >> 1].first;
        } else {
          buf << (j >> 1) + 1 << "b ";
          sum_b += s[j >> 1].second;
        }
        sum_a -= 1, sum_b -= 1;
      }
    }
    f64 sum = min(sum_a, sum_b);
    buf << "min(" << sum_a << "," << sum_b << ")=" << sum << nl;
    if (sum > ans) cerr << buf.str();
    ans = max(ans, sum);
  }
  cerr << fixed << setprecision(4);
  cerr << ans << nl;
}

int main() {
  fastio();
  i32 n = 0;
  cin >> n;
  vector<pair<f64, f64>> s(n);
  for (auto& [a, b] : s) cin >> a >> b;
  bruteforce(s);
  return 0;
}
