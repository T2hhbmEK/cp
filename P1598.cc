#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s;
  unordered_map<char, int> counter;
  for (int i = 1; i <= 4; i++) {
    getline(cin, s);
    for (char c : s) counter[c]++;
  }
  int n = 0;
  for (char c = 'A'; c <= 'Z'; c++) {
    n = max(n, counter[c]);
  }
  vector<string> a(n + 1, string(51, ' '));
  for (char c = 'A'; c <= 'Z'; c++) {
    a[0][2 * (c - 'A')] = c;
  }
  for (char c = 'A'; c <= 'Z'; c++) {
    for (int i = 1; i <= counter[c]; i++) {
      a[i][2 * (c - 'A')] = '*';
    }
  }
  reverse(a.begin(), a.end());
  for (auto &s : a) {
    while (!s.empty() && s.back() == ' ') s.pop_back();
    cout << s << endl;
  }
  return 0;
}
