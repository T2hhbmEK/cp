#include <iostream>
#include <string>
using namespace std;
string s, boy = "boy", girl = "girl";
int cntb, cntg;
int f(string t) {
  int n = s.size(), m = t.size();
  int cnt = 0;
  for (int i = 0; i + m <= n; i++) {
    bool flag = 0;
    for (int j = 0; j < m; j++) {
      if (s[i + j] == t[j]) {
        flag = 1;
        s[i + j] = '.';
      }
    }
    if (flag == 1) cnt++;
  }
  return cnt;
}
int main() {
  cin >> s;
  cout << f("boy") << endl << f("girl") << endl;
  return 0;
}
