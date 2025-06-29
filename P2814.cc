#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
  unordered_map<string, string> pa;
  function<string(string)> getPa = [&](string x) {
    if (pa.find(x) == pa.end()) pa[x] = x;
    return pa[x];
  };
  function<string(string)> find = [&](string x) {
    return getPa(x) == x ? x : find(getPa(x));
  };
  string s;
  string fa;
  while (cin >> s && s.front() != '$') {
    char op = s.front();
    string na = s.substr(1);
    if (op == '#') fa = na;
    if (op == '+') pa[na] = fa;
    if (op == '?') cout << na << " " << find(na) << '\n';
  }
  return 0;
}
