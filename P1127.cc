#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define maxn 1010
using namespace std;
int n;
string a[maxn];
map<char, vector<int>> e;
map<char, int> din, dout;
bool vis[maxn];
int ans[maxn];
bool dfs(int u, int k) {
  if (k > n) {
    for (int i = 1; i < k; ++i) cout << a[ans[i]] << ".\n"[i == k - 1];
    exit(0);
    return true;
  }
  for (int i : e[u]) {
    if (!vis[i]) {
      vis[i] = true;
      ans[k] = i;
      if (dfs(a[i].back(), k + 1)) return true;
      vis[i] = false;
    }
  }
  return false;
}
bool hasEulerianPath() {
  vector<char> src, dst;
  for (char u = 'a'; u <= 'z'; ++u) {
    if (din[u] - dout[u] == 1) {
      dst.push_back(u);
    } else if (din[u] - dout[u] == -1) {
      src.push_back(u);
    } else if (din[u] != dout[u]) {
      return false;
    }
  }
  if (src.size() != dst.size() || src.size() > 1) return false;
  char u = src.empty() ? e.begin()->first : src.front();
  return dfs(u, 1);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) e[a[i].front()].push_back(i);
  for (auto& [u, es] : e) {
    for (int i : es) {
      char v = a[i].back();
      dout[u]++;
      din[v]++;
    }
  }
  hasEulerianPath();
  cout << "***\n";
  return 0;
}
