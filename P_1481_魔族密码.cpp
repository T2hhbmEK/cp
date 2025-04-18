#include <bits/stdc++.h>
using namespace std;
#define N 200010
int nxt[N][26], cnt, w[N], n, ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    char s[100];
    scanf("%s", s);
    int p = 0;
    int _ans = 0;
    for (int j = 0; j < strlen(s); ++j) {
      int k = s[j] - 'a';
      if (!nxt[p][k]) {
        nxt[p][k] = ++cnt;
      }
      p = nxt[p][k];
      _ans += w[p];
    }
    ++w[p];
    ++_ans;
    if (_ans > ans) ans = _ans;
    // cout << s << " " << _ans << endl;
  }
  cout << ans << endl;
  return 0;
}