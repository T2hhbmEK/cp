#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define sz(x) (int)(x).size()
#define MAXN 100000
using namespace std;
using pci = pair<char, int>;
int n;
char c;
int l;
string s;
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> c >> l;
    if (sz(s) + l > 100) {
      cout << "Too Long" << endl;
      return 0;
    }
    while (l--) s += c;
  }
  cout << s << endl;
  return 0;
}
