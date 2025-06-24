#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int maxn = 10010;
namespace tree {
int v[maxn], ch[maxn][2], pa[maxn], cnt[maxn], rt, n;
int insert(int x) {
  v[++n] = x;
  cnt[n] = 1;
  if (rt == 0) return rt = n;
  int p = rt, pp = 0, ppi = 0;
  while (p != 0) {
    ppi = x < v[p] ? 0 : 1;
    cnt[p] += 1;
    pp = p;
    p = ch[p][ppi];
  }
  ch[pp][ppi] = n;
  pa[n] = pp;
  return n;
}
int rnk(int x) {
  int sum = 0;
  int p = rt;
  while (p != 0) {
    if (x == v[p]) return sum + cnt[ch[p][0]] + 1;
    if (x > v[p]) sum += cnt[ch[p][0]] + 1;
    p = ch[p][x >= v[p]];
  }
  return sum + 1;
}
int at(int x) {
  if (x < 1) return -inf;
  if (x > n) return inf;
  int sum = 0;
  int p = rt;
  while (sum + cnt[ch[p][0]] + 1 != x) {
    if (x <= sum + cnt[ch[p][0]]) {
      p = ch[p][0];
    } else {
      sum += cnt[ch[p][0]] + 1;
      p = ch[p][1];
    }
  }
  return v[p];
}
int pre(int x) {
  int i = rnk(x);
  return at(i - 1);
}
int nex(int x) {
  int i = rnk(x);
  int y = at(i);
  if (x == y) {
    return at(i + 1);
  } else {
    return at(i);
  }
}
}  // namespace tree
int main() {
  int q, op, x;
  cin >> q;
  while (q--) {
    cin >> op >> x;
    if (op == 1) {
      cout << tree::rnk(x) << '\n';
    } else if (op == 2) {
      cout << tree::at(x) << '\n';
    } else if (op == 3) {
      cout << tree::pre(x) << '\n';
    } else if (op == 4) {
      cout << tree::nex(x) << '\n';
    } else if (op == 5) {
      tree::insert(x);
    }
  }
  return 0;
}
