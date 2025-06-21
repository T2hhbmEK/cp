#include <cctype>
#include <iostream>
#include <string>
using namespace std;

string& tolower(string& s) {
  for (auto& c : s) {
    c = tolower(c);
  }
  return s;
}

int main() {
  int cnt = 0, p = -1;
  string t, s, w;
  cin >> t;
  t = tolower(t);
  getline(cin, s);  // skip 1st line
  getline(cin, s);
  s = tolower(s);
  for (int i = 0; i <= (int)s.size(); i++) {
    if (s[i] == ' ' || s[i] == '\0') {
      if (w == t) {
        cnt++;
        if (p == -1) {
          p = i - w.size();
        }
      }
      w = "";
    } else {
      w += s[i];
    }
  }
  if (p == -1) {
    cout << p << endl;
  } else {
    cout << cnt << " " << p << endl;
  }
  return 0;
}
