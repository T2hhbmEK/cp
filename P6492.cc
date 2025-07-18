#include <bits/stdc++.h>
using namespace std;

#define MAXN 200010

enum : int8_t { L = 0, R = 1 };

struct T {
  struct U {
    int of[2] = {};
  } at[2] = {};
  int mx = 0;
  int sz = 0;
} t[MAXN << 2];

ostream& operator<<(ostream& os, const T& x) {
  os << "[";
  for (int i : {L, R}) {
    os << "LR"[i] << "[";
    for (int j : {L, R}) os << x.at[i].of[j] << ",]"[j == R];
  }
  return os << x.mx << "]";
}

void dn(T& v) {
  for (int i : {L, R}) swap(v.at[i].of[L], v.at[i].of[R]);
}

T up(const T& x, const T& y) {
  T z{};
  const T* ch[2] = {&x, &y};
  for (int i : {L, R}) {    // left right
    for (int j : {L, R}) {  // value
      z.at[i].of[j] = ch[i]->at[i].of[j];
      if (ch[i]->at[i].of[j] == ch[i]->sz) {
        z.at[i].of[j] += ch[i ^ 1]->at[i].of[j ^ (ch[i]->sz & 1)];
      }
    }
  }
  z.mx = max({
      z.at[L].of[L],
      z.at[L].of[R],
      z.at[R].of[L],
      z.at[R].of[R],
      x.at[R].of[L] + y.at[L].of[R],
      x.at[R].of[R] + y.at[L].of[L],
      x.mx,
      y.mx,
  });
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
    for (int i : {L, R}) t[v].at[i].of[L] = 1;
    for (int i : {L, R}) t[v].at[i].of[R] = 0;
    t[v].mx = 1;
    t[v].sz = 1;
    return;
  }
  int tm = (tl + tr) / 2;
  build(v * 2 + L, tl, tm), build(v * 2 + R, tm + 1, tr);
  up(v);
}

void prt(int v, int tl, int tr, bool flag = false) {
  if (flag) {
    int n = 1 << (int)log2(tr - tl);
    int n4 = n << 2;
    for (int i = 1; i < n4; ++i) {
      cout << t[i] << ' ';
      int x = i + 1;
      if ((x & -x) == x) cout << '\n';
    }
  }
  for (int k = tl; k <= tr; ++k) cout << "LR"[qry(v, tl, tr, k, k).at[L].of[R]];
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
  // prt(1, 1, n);
  while (q--) {
    cin >> x;
    upd(1, 1, n, x, x);
    int y = max(qry(1, 1, n, 1, n).mx, qry(1, 1, n, 1, n).mx);
    cout << y << '\n';
    // prt(1, 1, n);
    // cout.flush();
  }
}

void test() {
  auto seed = time(nullptr);
  cout << "seed=" << seed << '\n';
  srand(seed);
  int maxn = 200;
  int n = rand() % maxn + 1;
  int q = rand() % maxn + 1;
  cout << n << " " << q << '\n';
  build(1, 1, n);
  string a(n, 'L');
  while (q--) {
    int x = rand() % n + 1;
    a[x - 1] = "LR"[a[x - 1] == 'L'];
    upd(1, 1, n, x, x);
    int y = max(qry(1, 1, n, 1, n).mx, qry(1, 1, n, 1, n).mx);

    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
      if (a[i] != a[i - 1]) dp[i] += dp[i - 1];
    }
    int z = *max_element(dp.begin(), dp.end());

    cout << a << '\n';
    cout << z << ' ';
    cout << y << '\n';
    if (z != y) {
      prt(1, 1, n, 1);
      cout.flush();
      getc(stdin);
    }
  }
  exit(0);
}

signed main() {
  // test();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
