#include <bits/stdc++.h>
#define MAXN 110
#define endl '\n'
using namespace std;
int n;
string s[MAXN];
set<string> st;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> s[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      st.insert(s[i] + s[j]);
      st.insert(s[j] + s[i]);
    }
  }
  cout << st.size() << endl;
  return 0;
}
