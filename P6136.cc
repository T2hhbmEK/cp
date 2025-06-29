#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
namespace treap {
constexpr int maxn = 1100010;
int a[maxn], ch[maxn][2], w[maxn], cnt[maxn], sz[maxn];
int root, tot;
string output(int k) {
  if (k == 0) return "*";
  ostringstream oss;
  oss << a[k] << ":" << w[k] << "[" << cnt[k] << "," << sz[k] << "]("
      << output(ch[k][0]) << "," << output(ch[k][1]) << ")";
  return oss.str();
}
int newItem(int x) {
  a[++tot] = x;
  w[tot] = rand();
  cnt[tot] = sz[tot] = 1;
  return tot;
}
void pushup(int k) {
  if (!k) return;
  sz[k] = cnt[k];
  for (int i : {0, 1}) {
    sz[k] += sz[ch[k][i]];
  }
}
void split(int t, int x, int &l, int &m, int &r) {
  if (t == 0) {
    l = m = r = 0;
    return;
  }
  if (x > a[t]) {
    split(ch[t][1], x, ch[t][1], m, r), l = t, pushup(l);
  } else if (x < a[t]) {
    split(ch[t][0], x, l, m, ch[t][0]), r = t, pushup(r);
  } else {  // x == a[t]
    l = ch[t][0], r = ch[t][1], m = t;
    ch[m][0] = ch[m][1] = 0, pushup(m);
  }
}
void splitByRank(int t, int k, int &l, int &m, int &r) {
  if (t == 0) {
    l = m = r = 0;
    return;
  }
  if (k > sz[ch[t][0]] + cnt[t]) {
    splitByRank(ch[t][1], k - (sz[ch[t][0]] + cnt[t]), ch[t][1], m, r),
        l = t, pushup(l);
  } else if (k <= sz[ch[t][0]]) {
    splitByRank(ch[t][0], k, l, m, ch[t][0]), r = t, pushup(r);
  } else {
    l = ch[t][0], r = ch[t][1], m = t;
    ch[m][0] = ch[m][1] = 0, pushup(m);
  }
}
int merge2(int l, int r) {
  if (l == 0) return r;
  if (r == 0) return l;
  if (w[l] < w[r]) {
    ch[l][1] = merge2(ch[l][1], r);
    pushup(l);
    return l;
  } else {
    ch[r][0] = merge2(l, ch[r][0]);
    pushup(r);
    return r;
  }
}
int merge(int l, int m, int r) { return merge2(l, merge2(m, r)); }
void insert(int x) {
  int l, m, r;
  split(root, x, l, m, r);
  if (m == 0) {
    m = newItem(x);
  } else {
    cnt[m]++;
    pushup(m);
  }
  root = merge(l, m, r);
}
void erase(int x) {
  int l, m, r;
  split(root, x, l, m, r);
  if (m && cnt[m] > 1) {
    cnt[m]--;
    pushup(m);
  } else {
    m = 0;
  }
  root = merge(l, m, r);
}
int lower_bound(int x) {
  int l, m, r;
  split(root, x, l, m, r);
  int k = sz[l] + 1;
  root = merge(l, m, r);
  return k;
}
int at(int k) {
  int l, m, r;
  splitByRank(root, k, l, m, r);
  int x = a[m];
  root = merge(l, m, r);
  return x;
}
int pre(int x) {
  int k = lower_bound(x);
  return at(k - 1);
}
int nex(int x) {
  int k = lower_bound(x + 1);
  return at(k);
}
}  // namespace treap
int n, m, op, x, last, ans;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  while (n--) {
    cin >> x;
    treap::insert(x);
  }
  while (m--) {
    cin >> op >> x;
    x ^= last;
    if (op == 1) treap::insert(x);
    if (op == 2) treap::erase(x);
    if (op == 3) ans ^= (last = treap::lower_bound(x));
    if (op == 4) ans ^= (last = treap::at(x));
    if (op == 5) ans ^= (last = treap::pre(x));
    if (op == 6) ans ^= (last = treap::nex(x));
    // cerr << treap::output(treap::root) << endl;
  }
  cout << ans << endl;
  return 0;
}
