#include <bits/stdc++.h>
#define fastio                      \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(nullptr);            \
  std::cout.tie(nullptr)
using namespace std;

int main() {
  fastio;
  string s;
  cin >> s;
  size_t pos;
  if ((pos = s.find(".")) != string::npos) {
    string a = s.substr(0, pos);
    string b = s.substr(pos + 1, s.size() - pos);
    while (a.size() > 1 && a.back() == '0') a.pop_back();
    reverse(a.begin(), a.end());
    while (b.size() > 1 && b.back() == '0') b.pop_back();
    reverse(b.begin(), b.end());
    while (b.size() > 1 && b.back() == '0') b.pop_back();
    cout << a << "." << b << endl;
  } else if ((pos = s.find("/")) != string::npos) {
    string a = s.substr(0, pos);
    string b = s.substr(pos + 1, s.size() - pos);
    while (a.size() > 1 && a.back() == '0') a.pop_back();
    reverse(a.begin(), a.end());
    while (b.size() > 1 && b.back() == '0') b.pop_back();
    reverse(b.begin(), b.end());
    cout << a << "/" << b << endl;
  } else if (s.back() == '%') {
    string a = s.substr(0, s.size() - 1);
    while (a.size() > 1 && a.back() == '0') a.pop_back();
    reverse(a.begin(), a.end());
    cout << a << "%" << endl;
  } else {
    string a = s;
    while (a.size() > 1 && a.back() == '0') a.pop_back();
    reverse(a.begin(), a.end());
    cout << a << endl;
  }
  return 0;
}
