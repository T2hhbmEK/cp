#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)(x).size()
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using pq = priority_queue<int, vi, greater<>>;

void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }

constexpr int INF = numeric_limits<int>::max();
constexpr int MAXN = 5e5 + 10;
constexpr int MOD = 998244353;

struct Node {
  string s;
  Node* pre;
} pool[MAXN];
int top;

Node* srv;
Node* pc[MAXN];
int n, q, op, p;

void prt(Node* p) {
  if (p == nullptr) return;
  prt(p->pre);
  cout << p->s;
}

void solve() {  //
  cin >> n >> q;
  while (q--) {
    cin >> op >> p;
    if (op == 1) {
      pc[p] = srv;
    } else if (op == 2) {
      cin >> pool[++top].s;
      pool[top].pre = pc[p];
      pc[p] = &pool[top];
    } else {
      srv = pc[p];
    }
  }
  prt(srv), cout << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
