#include <cassert>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <tuple>
#include <utility>
using namespace std;
namespace treap {
struct Node;
using pNode = unique_ptr<Node>;
struct Node {
  int val, prior, cnt, sz;
  pNode l, r;
  Node(int x) : val(x), prior(rand()), cnt(1), sz(1), l(nullptr), r(nullptr) {}
  void pushup() { sz = cnt + (l ? l->sz : 0) + (r ? r->sz : 0); }
};
inline int sz(const pNode &p) { return p ? p->sz : 0; }
ostream &operator<<(ostream &os, const pNode &t) {
  if (t == nullptr) return os << "null";
  return os << t->val << ":" << t->prior << "[" << t->cnt << "]" << "(" << t->l
            << "," << t->r << ")";
}
tuple<pNode, pNode, pNode> split(pNode t, int x) {
  if (t == nullptr) return {nullptr, nullptr, nullptr};
  pNode l, m, r;
  if (x > t->val) {
    tie(t->r, m, r) = split(std::move(t->r), x);
    t->pushup();
    return {std::move(t), std::move(m), std::move(r)};
  } else if (x < t->val) {
    tie(l, m, t->l) = split(std::move(t->l), x);
    t->pushup();
    return {std::move(l), std::move(m), std::move(t)};
  } else {
    l = std::move(t->l), r = std::move(t->r);
    t->pushup();
    return {std::move(l), std::move(t), std::move(r)};
  }
}
tuple<pNode, pNode, pNode> splitByRank(pNode t, int k) {
  if (t == nullptr) return {nullptr, nullptr, nullptr};
  pNode l, m, r;
  if (k > sz(t->l) + t->cnt) {
    tie(t->r, m, r) = splitByRank(std::move(t->r), k - sz(t->l) - t->cnt);
    t->pushup();
    return {std::move(t), std::move(m), std::move(r)};
  } else if (k <= sz(t->l)) {
    tie(l, m, t->l) = splitByRank(std::move(t->l), k);
    t->pushup();
    return {std::move(l), std::move(m), std::move(t)};
  } else {
    l = std::move(t->l), r = std::move(t->r);
    t->pushup();
    return {std::move(l), std::move(t), std::move(r)};
  }
}
pNode merge_(pNode l, pNode r) {
  if (l == nullptr) return r;
  if (r == nullptr) return l;
  if (l->prior < r->prior) {
    l->r = merge_(std::move(l->r), std::move(r));
    l->pushup();
    return l;
  } else {
    r->l = merge_(std::move(l), std::move(r->l));
    r->pushup();
    return r;
  }
}
pNode merge(pNode l, pNode m, pNode r) {
  return merge_(merge_(std::move(l), std::move(m)), std::move(r));
}
void insert(pNode &t, int x) {
  pNode l, m, r;
  tie(l, m, r) = split(std::move(t), x);
  if (m == nullptr) {
    m = make_unique<Node>(x);
  } else {
    m->cnt++;
    m->pushup();
  }
  t = merge(std::move(l), std::move(m), std::move(r));
}
void erase(pNode &t, int x) {
  pNode l, m, r;
  tie(l, m, r) = split(std::move(t), x);
  if (m && m->cnt > 1) {
    m->cnt--;
    m->pushup();
  } else {
    m = nullptr;
  }
  t = merge(std::move(l), std::move(m), std::move(r));
}
int lower_bound(pNode &t, int x) {
  pNode l, m, r;
  tie(l, m, r) = split(std::move(t), x);
  int ret = sz(l) + 1;
  t = merge(std::move(l), std::move(m), std::move(r));
  return ret;
}
int at(pNode &t, int k) {
  pNode l, m, r;
  tie(l, m, r) = splitByRank(std::move(t), k);
  if (m == nullptr) cout << l << endl << m << endl << r << endl;
  assert(m != nullptr);
  int ret = m->val;
  t = merge(std::move(l), std::move(m), std::move(r));
  return ret;
}
int pre(pNode &t, int x) {
  int k = lower_bound(t, x);
  return at(t, k - 1);
}
int nex(pNode &t, int x) {
  int k = lower_bound(t, x + 1);
  return at(t, k);
}
}  // namespace treap
int main() {
  int n;
  cin >> n;
  treap::pNode root = nullptr;
  while (n--) {
    int op, x;
    cin >> op >> x;
    if (op == 1) treap::insert(root, x);
    if (op == 2) treap::erase(root, x);
    if (op == 3) cout << treap::lower_bound(root, x) << '\n';
    if (op == 4) cout << treap::at(root, x) << '\n';
    if (op == 5) cout << treap::pre(root, x) << '\n';
    if (op == 6) cout << treap::nex(root, x) << '\n';
  }
  return 0;
}
