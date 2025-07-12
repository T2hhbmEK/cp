#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define sz(x) (int)(x).size()
#define MAXN 1000000
using namespace std;
using pci = pair<char, int>;
int a, n, ans;
int f1(int x) {
  string s = to_string(x);
  int sum = 0;
  for (char c : s) sum = sum * 10 + (c - '0');
  reverse(s.begin(), s.end());
  for (char c : s) sum = sum * 10 + (c - '0');
  return sum;
}
int f2(int x) {
  string s = to_string(x);
  int sum = 0;
  for (char c : s) sum = sum * 10 + (c - '0');
  s = s.substr(0, sz(s) - 1);
  reverse(s.begin(), s.end());
  for (char c : s) sum = sum * 10 + (c - '0');
  return sum;
}
bool chk(int x) {
  string s;
  while (x) {
    s += static_cast<char>('0' + x % a);
    x /= a;
  }
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> a >> n;
  for (int i = 1; i < MAXN; ++i) {
    int x = f1(i), y = f2(i);
    for (int x : {f1(i), f2(i)}) {
      if (x <= n && chk(x)) ans += x;
    }
  }
  cout << ans << endl;
  return 0;
}
