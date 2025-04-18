#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 105;
string s[N];
bool chk(string& t) {
  for (int i = 1; i < (int)t.size(); i++) {
    if (t[i] < t[i - 1]) return 0;
  }
  return 1;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  sort(s + 1, s + 1 + n);
  string t = "";
  for (int i = 1; i <= n; i++) t += s[i];
  cout << chk(t) << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}