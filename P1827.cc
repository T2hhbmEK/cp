#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;
using Tree = unordered_map<char, pair<int, int>>;
char buildTree(const string& sm, const string& sp, Tree& tr) {
  // cerr << sm << ' ' << sp << '\n';
  assert(sm.length() == sp.length());
  if (sm.length() == 0) return 0;
  char rt = sp.front();
  int md = sm.find(rt);
  char lch = buildTree(sm.substr(0, md), sp.substr(1, md), tr);
  char rch = buildTree(sm.substr(md + 1), sp.substr(md + 1), tr);
  tr[rt] = {lch, rch};
  return rt;
}
void dfs(Tree& tr, char root) {
  if (root == 0) return;
  dfs(tr, tr[root].first);
  dfs(tr, tr[root].second);
  cout << root;
}
int main() {
  string s_mid, s_pre;
  cin >> s_mid >> s_pre;
  Tree tree;
  char root = buildTree(s_mid, s_pre, tree);
  dfs(tree, root);
  cout << '\n';
  return 0;
}
