#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 20
using namespace std;

int n, s[maxn], b[maxn], ans = inf;

void dfs() {
  for (int i = 1; i < (1 << n); i++) {
    int ss = 1, sb = 0;
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        ss *= s[j];
        sb += b[j];
      }
    }
    cerr << "0b" << bitset<10>(i) << " " << ss << " " << sb << endl;
    ans = min(ans, abs(ss - sb));
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> b[i];
  }
  dfs();
  cout << ans;
  return 0;
}
