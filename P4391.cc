#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define MAXN 1000010
using namespace std;
int n;
string s;
int z[MAXN];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> s;
  assert(n == sz(s));
  z[0] = -1;
  for (int i = 1; i < n; ++i) {
    int x = z[i - 1];
    while (x >= 0 && s[i] != s[x + 1]) x = z[x];
    z[i] = s[i] == s[x + 1] ? x + 1 : -1;
  }
  cout << (n - 1) - z[n - 1] << '\n';
  return 0;
}
