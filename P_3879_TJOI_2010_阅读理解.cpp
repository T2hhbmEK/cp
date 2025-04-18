#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define NN 5000005
int n, nxt[NN][26], cnt, m;
vector<int> ans[NN];
char s[21];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int l;
    scanf("%d", &l);
    for (int j = 1; j <= l; ++j) {
      scanf("%s", s);
      int p = 0;
      for (int k = 0; k < strlen(s); ++k) {
        int x = s[k] - 'a';
        if (!nxt[p][x]) {
          nxt[p][x] = ++cnt;
        }
        p = nxt[p][x];
      }
      if (ans[p].empty() || ans[p].back() != i) {
        ans[p].push_back(i);
      }
    }
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    scanf("%s", s);
    int p = 0;
    for (int k = 0; k < strlen(s); ++k) {
      int x = s[k] - 'a';
      if (!nxt[p][x]) {
        p = 0;
        break;
      }
      p = nxt[p][x];
    }
    for (int i = 0; i < ans[p].size(); ++i) {
      printf(i == 0 ? "%d" : " %d", ans[p][i]);
    }
    printf("\n");
  }
  return 0;
}
