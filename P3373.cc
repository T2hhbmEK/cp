#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T1 = int, typename T2 = int>
struct SegTree {
  using node = pair<T1, T2>;
  SegTree(int tl, int tr) : tl_(tl), tr_(tr), n4_((tr - tl + 1) * 4), t_(n4_) {}
  void init(int a[]) { init(1, tl_, tr_, a); }
  T1 qry(int l, int r) { return qry(1, tl_, tr_, l, r); }
  void upd(int l, int r, T2 x) { upd(1, tl_, tr_, l, r, x); }
  friend ostream& operator<<(ostream& os, SegTree& t) {
    for (int i = t.tl_; i <= t.tr_; ++i) os << t.qry(i, i) << ' ';
    return os;
  }

 private:
  int tl_, tr_, n4_;
  vector<pair<T1, T2>> t_;
  virtual T1 up(const T1& tl, const T1& tr) = 0;
  virtual void dn(node& v, int tl, int tr, const T2& x) = 0;
  void dn(int v, int tl, int tr) {
    if (tl == tr) return;
    int tm = tl + (tr - tl) / 2;
    dn(t_[v * 2], tl, tm, t_[v].second);
    dn(t_[v * 2 + 1], tm + 1, tr, t_[v].second);
    up(v);
  }
  void up(int v) { t_[v] = {up(t_[v * 2].first, t_[v * 2 + 1].first), T2{}}; }
  void init(int v, int tl, int tr, int a[]) {
    if (tl == tr) return void(t_[v].first = T1{a[tl]});
    int tm = tl + (tr - tl) / 2;
    init(v * 2, tl, tm, a), init(v * 2 + 1, tm + 1, tr, a), up(v);
  }
  T1 qry(int v, int tl, int tr, int l, int r) {
    if (r < tl || tr < l) return T1{};
    if (l <= tl && tr <= r) return t_[v].first;
    dn(v, tl, tr);
    int tm = tl + (tr - tl) / 2;
    return up(qry(v * 2, tl, tm, l, r), qry(v * 2 + 1, tm + 1, tr, l, r));
  }
  void upd(int v, int tl, int tr, int l, int r, const T2& x) {
    if (r < tl || tr < l) return;
    if (l <= tl && tr <= r) return dn(t_[v], tl, tr, x);
    dn(v, tl, tr);
    int tm = tl + (tr - tl) / 2;
    upd(v * 2, tl, tm, l, r, x), upd(v * 2 + 1, tm + 1, tr, l, r, x);
    up(v);
  }
};

struct Lazy {
  int k = 1, b = 0;
};

struct SegTreeAddMul : SegTree<int, Lazy> {
  const int MOD;
  SegTreeAddMul(int tl, int tr, int m) : SegTree<int, Lazy>(tl, tr), MOD(m) {}
  int up(const int& tl, const int& tr) override { return (tl + tr) % MOD; }
  void dn(node& v, int tl, int tr, const Lazy& x) override {
    auto& [k, b] = v.second;
    v.first = (v.first * x.k + x.b * (tr - tl + 1)) % MOD;
    k = k * x.k % MOD, b = (b * x.k + x.b) % MOD;
  }
  void mul(int l, int r, int x) { upd(l, r, {.k = x, .b = 0}); }
  void add(int l, int r, int x) { upd(l, r, {.k = 1, .b = x}); }
};

int n, q, m;

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> q >> m;
  vector<int> a(1 + n);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  SegTreeAddMul t(1, n, m);
  t.init(a.data());
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
      cout << t.qry(x, y) << '\n';
    }
  }
  return 0;
}
