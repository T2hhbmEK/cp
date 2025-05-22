#include <bits/stdc++.h>
using namespace std;
unordered_map<string, string> mp;
int main() {
  int n;
  cin >> n;
  string a, b;
  while (n--) {
    cin >> a >> b;
    mp[a] = b;
  }
  string s;
  cin >> s;
  string t = "";
  for (int i = 0; i <= (int)s.size(); i++) {
    if (isalpha(s[i])) {
      t += s[i];
    } else {
      if (t.size()) {
        // cerr << t << endl;
        string w = "UNK";
        if (mp.find(t) != mp.end()) w = mp[t];
        cout << w;
      }
      cout << s[i];
      t = "";
    }
  }
  return 0;
}