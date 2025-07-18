#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int t[MAXN << 2];
int lazy[MAXN << 2];

int lc(int v) { return v * 2; }
int rc(int v) { return v * 2 + 1; }
int mid(int tl, int tr) { return tl + (tr - tl) / 2; }

int gather(int x, int y) { return x | y; }
void pushup(int v) { t[v] = gather(t[lc(v)], t[rc(v)]), lazy[v] = 0; }

void scatter(int v, int x) { x ? t[v] = x, lazy[v] = x : 0; }
void pushdown(int v) { scatter(lc(v), lazy[v]), scatter(rc(v), lazy[v]), pushup(v); }

int query(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) return 0;
  if (l <= tl && tr <= r) return t[v];
  int tm = mid(tl, tr);
  pushdown(v);
  return gather(query(lc(v), tl, tm, l, r), query(rc(v), tm + 1, tr, l, r));
}

void update(int v, int tl, int tr, int l, int r, int x) {
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) return scatter(v, x);
  int tm = mid(tl, tr);
  pushdown(v);
  update(lc(v), tl, tm, l, r, x), update(rc(v), tm + 1, tr, l, r, x), pushup(v);
}

int n, m, q;
int a, b, c = 1;

void solve() {
  cin >> n >> m >> q;
  update(1, 1, n, 1, n, 1 << c);
  while (q--) {
    char op;
    cin >> op >> a >> b;
    if (a > b) swap(a, b);
    if (op == 'C') {
      cin >> c, update(1, 1, n, a, b, 1 << c);
    } else {
      cout << __builtin_popcount(query(1, 1, n, a, b)) << '\n';
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
