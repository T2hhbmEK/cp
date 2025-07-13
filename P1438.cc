#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
using namespace std;
constexpr int MAXN = 100010;
class SegTree {
 private:
  int tl, tr;
  vector<int> t, lazy;
  void apply(int v, int tl, int tr, int x) {
    lazy[v] += x;
    t[v] += (tr - tl + 1) * x;
  }
  void gather(int v) { t[v] = t[v << 1] + t[(v << 1) + 1]; }
  void pushdown(int v, int tl, int tr) {
    if (tl == tr) return;
    int tm = tl + ((tr - tl) >> 1);
    apply(v << 1, tl, tm, lazy[v]), apply((v << 1) + 1, tm + 1, tr, lazy[v]);
    lazy[v] = 0;
  }
  void build(int v, int tl, int tr, int a[]) {
    if (tl == tr) return void(t[v] = a[tl]);
    int tm = tl + ((tr - tl) >> 1);
    build(v << 1, tl, tm, a), build((v << 1) + 1, tm + 1, tr, a);
    gather(v);
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
  void show(int v, int tl, int tr) {
    if (tl == tr) return void(cout << t[v]);
    int tm = tl + ((tr - tl) >> 1);
    pushdown(v, tl, tr);
    show(v << 1, tl, tm), show((v << 1) + 1, tm + 1, tr);
  }

 public:
  explicit SegTree(int tl, int tr, int a[])
      : tl(tl), tr(tr), t((tr - tl + 1) << 2), lazy((tr - tl + 1) << 2) {
    if (a == nullptr) return;
    build(1, tl, tr, a);
  }
  void update(int l, int r, int x) {
    if (l > r) return;
    update(1, tl, tr, l, r, x);
  }
  int query(int l, int r) {
    if (l > r) return 0;
    return query(1, tl, tr, l, r);
  }
};
int n, m;
int a[MAXN];
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = n; i >= 1; --i) a[i] -= a[i - 1];
  SegTree t(1, n, a);
  while (m--) {
    int opt, l, r, K, D, p;
    cin >> opt;
    if (opt == 1) {
      cin >> l >> r >> K >> D;
      // a[l-1] += 0
      // a[l]   += K
      // a[l+1] += K+D
      // a[l+2] += k+2D
      // ...
      // a[r]   += K+(r-l)D
      // a[r+1] += 0
      t.update(l, l, K);
      t.update(l + 1, r, D);
      t.update(r + 1, r + 1, -K - (r - l) * D);
    } else {
      cin >> p;
      cout << t.query(1, p) << '\n';
    }
    // for (int i = 1; i <= n; ++i) {
    //   cerr << t.query(1, i) << " \n"[i == n];
    // }
  }
  return 0;
}
