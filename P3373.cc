#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegTree {
  struct node {
    int sum = 0, add = 0, mul = 1;
    explicit node() = default;
    explicit node(int x) : sum(x) {}
    explicit node(int x, int y, int z) : sum(x), add(y), mul(z) {}
  };
  int tl_, tr_, n4;
  vector<node> t;
  static int lch(int v) { return 2 * v; }
  static int rch(int v) { return 2 * v + 1; }
  static int mid(int tl, int tr) { return tl + (tr - tl) / 2; }
  virtual node pushup(const node& tl, const node& tr) {
    return node(tl.sum + tr.sum);
  }
  virtual void pushdown(node& v, int tl, int tr, const node& x) {
    // y=kx+b y'=k'y+b'=k'kx+k'b+b'
    v.sum = v.sum * x.mul + x.add * (tr - tl + 1);
    v.mul = v.mul * x.mul;
    v.add = v.add * x.mul + x.add;
  }
  void pushdown(int v, int tl, int tr) {
    if (tl == tr) return;
    pushdown(t[lch(v)], tl, mid(tl, tr), t[v]);
    pushdown(t[rch(v)], mid(tl, tr) + 1, tr, t[v]);
    pushup(v);
  }
  void pushup(int v) { t[v] = pushup(t[lch(v)], t[rch(v)]); }
  void build(int v, int tl, int tr, int a[]) {
    if (tl == tr) return void(t[v] = node(a[tl]));
    build(lch(v), tl, mid(tl, tr), a);
    build(rch(v), mid(tl, tr) + 1, tr, a);
    pushup(v);
  }
  node query(int v, int tl, int tr, int l, int r) {
    if (r < tl || tr < l) return node();
    if (l <= tl && tr <= r) return t[v];
    pushdown(v, tl, tr);
    return pushup(query(lch(v), tl, mid(tl, tr), l, r),
                  query(rch(v), mid(tl, tr) + 1, tr, l, r));
  }
  void update(int v, int tl, int tr, int l, int r, const node& x) {
    if (r < tl || tr < l) return;
    if (l <= tl && tr <= r) return pushdown(t[v], tl, tr, x);
    pushdown(v, tl, tr);
    update(lch(v), tl, mid(tl, tr), l, r, x);
    update(rch(v), mid(tl, tr) + 1, tr, l, r, x);
    pushup(v);
  }
  SegTree(int tl, int tr, int a[]) : tl_(tl), tr_(tr) {
    int n = tr - tl + 1;
    for (n4 = 1; n4 < n; n4 <<= 1);
    t.resize(n4 <<= 1);
    build(1, tl, tr, a);
  }
  int query(int l, int r) { return query(1, tl_, tr_, l, r).sum; }
  void add(int l, int r, int x) { update(1, tl_, tr_, l, r, node(0, x, 1)); }
  void mul(int l, int r, int x) { update(1, tl_, tr_, l, r, node(0, 0, x)); }
  friend ostream& operator<<(ostream& os, SegTree& t) {
    for (int i = 1; i < t.n4; ++i) {
      os << format("[{},{},{}] ", t.t[i].sum, t.t[i].add, t.t[i].mul)
         << " \n"[i + 1 == 1 << static_cast<int>(log2(i + 1))];
    }
    for (int i = t.tl_; i <= t.tr_; ++i) os << t.query(i, i) << ' ';
    return os;
  }
};

constexpr int MAXN = 100010;
int MOD = numeric_limits<int>::max();
struct SegTreeMod : SegTree {
  SegTreeMod(int tl, int tr, int a[]) : SegTree(tl, tr, a) {}
  node pushup(const node& tl, const node& tr) override {
    return node((tl.sum + tr.sum) % MOD);
  }
  void pushdown(node& v, int tl, int tr, const node& x) override {
    SegTree::pushdown(v, tl, tr, x);
    v.sum %= MOD, v.add %= MOD, v.mul %= MOD;
  }
};
int n, q, a[MAXN];
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> q >> MOD;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  SegTreeMod t(1, n, a);
  // cerr << t << endl;
  while (q--) {
    int op, x, y, k;
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> k;
      t.mul(x, y, k);
    } else if (op == 2) {
      cin >> x >> y >> k;
      t.add(x, y, k);
    } else {
      cin >> x >> y;
      cout << t.query(x, y) % MOD << '\n';
    }
    // cerr << t << endl;
  }
  return 0;
}
