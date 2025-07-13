#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
using namespace std;
struct SegTree {
 private:
  struct Lazy {
    int addend, assignment;
    bool marked;
    static Lazy ADD(int x) {
      return {.addend = x, .assignment = 0, .marked = false};
    }
    static Lazy SET(int x) {
      return {.addend = 0, .assignment = x, .marked = true};
    }
    void merge(const Lazy& x) {
      if (x.marked) {
        marked = x.marked;
        assignment = x.assignment;
        addend = 0;
      }
      addend += x.addend;
    }
  };
  struct Data {
    int sum;
    int max;
    int min;
    void set(int x) { sum = x, max = x, min = x; }
    friend Data gather(const Data& x, const Data& y) {
      return {.sum = x.sum + y.sum,
              .max = std::max(x.max, y.max),
              .min = std::min(x.min, y.min)};
    }
    void apply(int tl, int tr, const Lazy& x) {
      if (x.marked) {
        sum = (tr - tl + 1) * x.assignment;
        max = x.assignment;
        min = x.assignment;
      }
      sum += (tr - tl + 1) * x.addend;
      max += x.addend;
      min += x.addend;
    }
  };
  constexpr static Data EMPTY_VALUE = {.sum = 0,
                                       .max = numeric_limits<int>::min(),
                                       .min = numeric_limits<int>::max()};
  int tl, tr;
  vector<Data> t;
  vector<Lazy> lazy;
  void apply(int v, [[maybe_unused]] int tl, [[maybe_unused]] int tr,
             const Lazy& x) {
    t[v].apply(tl, tr, x);
    lazy[v].merge(x);
  }
  void pushdown(int v, int tl, int tr) {
    if (tl == tr) return;
    int tm = tl + ((tr - tl) >> 1);
    apply(v * 2, tl, tm, lazy[v]), apply(v * 2 + 1, tm + 1, tr, lazy[v]);
    lazy[v] = {};
  }
  void build(int v, int tl, int tr, int a[]) {
    if (tl == tr) return t[v].set(a[tl]);
    int tm = tl + ((tr - tl) >> 1);
    build(v * 2, tl, tm, a), build(v * 2 + 1, tm + 1, tr, a);
    t[v] = gather(t[v * 2], t[v * 2 + 1]);
  }
  Data query(int v, int tl, int tr, int l, int r) {
    if (r < tl || l > tr) return EMPTY_VALUE;
    if (l <= tl && r >= tr) return t[v];
    int tm = tl + ((tr - tl) >> 1);
    pushdown(v, tl, tr);
    return gather(query(v * 2, tl, tm, l, r),
                  query(v * 2 + 1, tm + 1, tr, l, r));
  }
  void update(int v, int tl, int tr, int l, int r, const Lazy& x) {
    if (r < tl || l > tr) return;
    if (l <= tl && r >= tr) return apply(v, tl, tr, x);
    int tm = tl + ((tr - tl) >> 1);
    pushdown(v, tl, tr);
    update(v * 2, tl, tm, l, r, x), update(v * 2 + 1, tm + 1, tr, l, r, x);
    t[v] = gather(t[v * 2], t[v * 2 + 1]);
  }
  void show(int v, int tl, int tr, ostream& os) {
    pushdown(v, tl, tr);
    if (tl == tr) return void(os << t[v].sum << ' ');
    int tm = tl + ((tr - tl) >> 1);
    show(v * 2, tl, tm, os), show(v * 2 + 1, tm + 1, tr, os);
  }

 public:
  explicit SegTree(int tl, int tr, int a[])
      : tl(tl), tr(tr), t((tr - tl + 1) * 4), lazy((tr - tl + 1) * 4) {
    if (a == nullptr) return;
    build(1, tl, tr, a);
  }
  int sum(int l, int r) { return query(1, tl, tr, l, r).sum; }
  int max(int l, int r) { return query(1, tl, tr, l, r).max; }
  int min(int l, int r) { return query(1, tl, tr, l, r).min; }
  void add(int l, int r, int x) { update(1, tl, tr, l, r, Lazy::ADD(x)); }
  void set(int l, int r, int x) { update(1, tl, tr, l, r, Lazy::SET(x)); }
  friend ostream& operator<<(ostream& os, SegTree& t) {
    t.show(1, t.tl, t.tr, os);
    return os;
  }
};
const int MAXN = 1000010;
int n, m;
int a[MAXN];
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  SegTree t(1, n, a);
  while (m--) {
    int op, l, r, x;
    cin >> op;
    if (op == 1) {
      cin >> l >> r >> x;
      t.set(l, r, x);
    } else if (op == 2) {
      cin >> l >> r >> x;
      t.add(l, r, x);
    } else {
      cin >> l >> r;
      cout << t.max(l, r) << '\n';
    }
    // cout << t << '\n';
  }
  return 0;
}
