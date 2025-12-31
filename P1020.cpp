#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
struct node {
  int l, r, maxx;
} tree[N << 2];  // !!!FIX
struct node2 {
  int v, p;
} a[N];
int dp[N], n, t[N];
void up(int now) {
  tree[now].maxx = max(tree[now << 1].maxx, tree[now << 1 | 1].maxx);
}
void build(int now, int l, int r) {
  tree[now].l = l, tree[now].r = r;
  if (l == r) {
    tree[now].maxx = 0;
    return;
  }
  int mid = (l + r) >> 1;
  build(now << 1, l, mid);
  build(now << 1 | 1, mid + 1, r);
  up(now);
}
void change(int now, int p, int x) {
  if (tree[now].l == tree[now].r) {
    tree[now].maxx = x;
    return;
  }
  int mid = (tree[now].l + tree[now].r) >> 1;
  if (p <= mid)
    change(now << 1, p, x);
  else
    change(now << 1 | 1, p, x);
  up(now);
}
int query(int now, int L, int R) {
  if (L <= tree[now].l && R >= tree[now].r) {
    return tree[now].maxx;
  }
  int Max = 0;
  int mid = (tree[now].l + tree[now].r) >> 1;
  if (L <= mid) Max = max(Max, query(now << 1, L, R));
  if (R > mid) Max = max(Max, query(now << 1 | 1, L, R));
  return Max;
}
bool cmp1(node2 x, node2 y) {
  if (x.v == y.v) return x.p < y.p;  // FIX
  return x.v > y.v;
}
bool cmp2(node2 x, node2 y) {
  if (x.v == y.v) return x.p > y.p;  // FIX 为什么没用
  return x.v < y.v;
}
int find(int x) {
  int l = 1, r = n, mid, res;
  res = 0;  // FIX
  while (l <= r) {
    mid = (l + r) >> 1;
    if (a[mid].v < x) {
      l = mid + 1;
      res = mid;
    } else {
      r = mid - 1;
    }
  }
  return res;
}
int main() {
  while (cin >> a[++n].v) {
    t[n] = a[n].v, a[n].p = n;
  }
  n--;
  sort(a + 1, a + 1 + n, cmp1);
  for (int i = 1; i <= n; i++) {
    t[a[i].p] = i;
  }
  build(1, 1, n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int j = t[i];
    dp[j] = query(1, 1, j) + 1;
    change(1, j, dp[j]);
    ans = max(ans, dp[j]);
  }
  cout << ans << endl;
  ans = 0;
  memset(tree, 0, sizeof(tree));
  build(1, 1, n);
  memset(dp, 0, sizeof(dp));
  sort(a + 1, a + 1 + n, cmp2);
  // cout<<a[21].v<<" "<<a[21].p<<" "<<a[22].v<<" "<<a[22].p<<" ";
  for (int i = 1; i <= n; i++) {
    t[a[i].p] = i;
  }
  for (int i = 1; i <= n; i++) {
    int j = t[i];
    int jj = find(a[j].v);
    fprintf(stderr, "%d %d %d\n", i, j, jj);
    dp[j] = query(1, 1, find(a[j].v)) + 1;
    change(1, j, dp[j]);
    ans = max(ans, dp[j]);
  }
  cout << ans << endl;
  return 0;
}
