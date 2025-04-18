#include <bits/stdc++.h>
using namespace std;

#define sz(s) (int)(s).size()

const int maxn = 2005;
string a, b;
int f[maxn][maxn];  // a[:i] -> a[:j] min edits

int main() {
  cin >> a >> b;
  for (int i = 1, j = 0; i <= sz(a); i++) {
    f[i][j] = i;
  }
  for (int j = 1, i = 0; j <= sz(b); j++) {
    f[i][j] = j;
  }
  for (int i = 1; i <= sz(a); i++) {
    for (int j = 1; j <= sz(b); j++) {
      f[i][j] = min({
          f[i - 1][j] + 1,                           // delete a / insert b
          f[i][j - 1] + 1,                           // delete b / insert a
          f[i - 1][j - 1] + (a[i - 1] != b[j - 1]),  // modify a/b
      });
    }
  }
  cout << f[sz(a)][sz(b)];
  return 0;
}
