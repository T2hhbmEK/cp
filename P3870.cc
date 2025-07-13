#include <bits/stdc++.h>
using namespace std;

namespace segtree {
constexpr int MAXN = 100010;
int t[MAXN << 2], lazy[MAXN << 2];
void apply(int v, int tl, int tr, int x) {
  lazy[v] ^= x;
  if (x & 1) t[v] = tr - tl + 1 - t[v];
}
void gather(int v) { t[v] = t[v << 1] + t[(v << 1) + 1]; }
void pushdown(int v, int tl, int tr) {
  if (tl == tr) return;
  int tm = tl + ((tr - tl) >> 1);
  apply(v << 1, tl, tm, lazy[v]), apply((v << 1) + 1, tm + 1, tr, lazy[v]);
  lazy[v] = 0;
}
int query(int v, int tl, int tr, int l, int r) {
  if (r < tl || l > tr) return 0;
  if (l <= tl && r >= tr) return t[v];
  int tm = tl + ((tr - tl) >> 1);
  pushdown(v, tl, tr);
  return query(v << 1, tl, tm, l, r) + query((v << 1) + 1, tm + 1, tr, l, r);
}
void update(int v, int tl, int tr, int l, int r, int x) {
  if (r < tl || l > tr) return;
  if (l <= tl && r >= tr) return apply(v, tl, tr, x);
  int tm = tl + ((tr - tl) >> 1);
  pushdown(v, tl, tr);
  update(v << 1, tl, tm, l, r, x), update((v << 1) + 1, tm + 1, tr, l, r, x);
  gather(v);
}
};  // namespace segtree
using namespace segtree;
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b, c;
    cin >> c >> a >> b;
    if (c == 0) {
      update(1, 1, n, a, b, 1);
    } else {
      cout << query(1, 1, n, a, b) << '\n';
    }
  }
  return 0;
}
