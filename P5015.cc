#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int cnt = 0;
  string s;
  getline(cin, s);
  for (auto c : s) {
    if (!isspace(c)) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
