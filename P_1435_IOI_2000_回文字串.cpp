#include <bits/stdc++.h>
#define maxn 1010
#define inf 0x3f3f3f3f
using namespace std;

int n, f[maxn][maxn];  // f[i][j]: [i,j] ops
string s;

int main() {
  cin >> s, n = s.size();
  for (int j = 1; j <= n; j++) {
    for (int i = j; i >= 1; i--) {
      if (s[i - 1] == s[j - 1]) {
        f[i][j] = f[i + 1][j - 1];
      } else {
        f[i][j] = min({
            f[i + 1][j] + 1,  // insert after j
            f[i][j - 1] + 1,  // insert before i
        });
      }
    }
  }
  cout << f[1][n];
  return 0;
}
