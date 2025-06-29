#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  queue<string> q;
  q.push("");
  vector<string> a;
  while (q.front().length() <= 6) {
    auto& cur = q.front();
    q.pop();
    a.push_back(cur);
    if (cur == s) {
      cout << a.size() - 1 << endl;
      return 0;
    }
    for (char i = cur.length() ? cur.back() + 1 : 'a'; i <= 'z'; ++i) {
      q.push(cur + i);
    }
  }
  cout << 0 << endl;
  return 0;
}
