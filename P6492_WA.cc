#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

enum : int8_t { L = 0, R = 1, M = 2 };

struct T {
  struct U {
    int of[2] = {};
  } at[3] = {};
  int sz = 0;
} t[MAXN << 2];

ostream& operator<<(ostream& os, const T& x) {
  os << "[";
  for (int i : {L, R, M}) {
    os << "LRM"[i] << "[";
    for (int j : {L, R}) os << x.at[i].of[j] << ",]"[j];
  }
  return os << "]";
}

void dn(T& v) {
  for (int i : {L, R, M}) swap(v.at[i].of[L], v.at[i].of[R]);
}

T up(const T& x, const T& y) {
  T z{};
  const T* ch[2] = {&x, &y};
  for (int i : {L, R}) {    // left right
    for (int j : {L, R}) {  // value
      z.at[i].of[j] = ch[i]->at[i].of[j];
      if (ch[i]->at[i].of[j] == ch[i]->sz) {
        z.at[i].of[j] += ch[i ^ 1]->at[i].of[j];
      }
    }
  }
  for (int i = M; int j : {L, R}) {  // value
    z.at[i].of[j] = max({
        z.at[L].of[j],
        z.at[R].of[j],
        x.at[R].of[j] + y.at[L].of[j],
    });
  }
  z.sz = x.sz + y.sz;
  return z;
}

void up(int v) { t[v] = up(t[v * 2 + L], t[v * 2 + R]); }

void upd(int v, int tl, int tr, int l, int r) {
  if (r < tl || l > tr) return;
  if (l <= tl && tr <= r) return dn(t[v]);
  int tm = (tl + tr) / 2;
  upd(v * 2 + L, tl, tm, l, r), upd(v * 2 + R, tm + 1, tr, l, r);
  up(v);
}

T qry(int v, int tl, int tr, int l, int r) {
  if (r < tl || l > tr) return T{};
  if (l <= tl && tr <= r) return t[v];
  int tm = (tl + tr) / 2;
  return up(qry(v * 2 + L, tl, tm, l, r), qry(v * 2 + R, tm + 1, tr, l, r));
}

void build(int v, int tl, int tr) {
  if (tl == tr) {
    for (int i : {L, R, M}) t[v].at[i].of[L] = 1;
    for (int i : {L, R, M}) t[v].at[i].of[R] = 0;
    t[v].sz = 1;
    return;
  }
  int tm = (tl + tr) / 2;
  build(v * 2 + L, tl, tm), build(v * 2 + R, tm + 1, tr);
  up(v);
}

void prt(int v, int tl, int tr) {
  int n = 1 << (int)log2(tr - tl);
  int n4 = n << 2;
  for (int i = 1; i < n4; ++i) {
    cout << t[i] << ' ';
    int x = i + 1;
    if ((x & -x) == x) cout << '\n';
  }
  for (int k = tl; k <= tr; ++k) cout << "LR"[qry(v, tl, tr, k, k).at[M].of[R]];
  cout << '\n';
}

int prevPowerOfTwo(int x) { return x > 1 ? prevPowerOfTwo(x / 2) * 2 : 1; }
int nextPowerOfTwo(int x) { return x > 1 ? prevPowerOfTwo(x - 1) * 2 : 1; }

void solve() {
  // Longest identical substring
  // Initailly, all filled with L
  // Each time, filp a char at pos x
  int n, q, x;
  cin >> n >> q;
  // n = nextPowerOfTwo(n);
  build(1, 1, n);
  prt(1, 1, n);
  while (q--) {
    cin >> x;
    upd(1, 1, n, x, x);
    prt(1, 1, n);
    int y = max(qry(1, 1, n, 1, n).at[M].of[L], qry(1, 1, n, 1, n).at[M].of[R]);
    cout << y << '\n';
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
