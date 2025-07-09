#include <bits/stdc++.h>
#define MAXN 110
#define endl '\n'
using namespace std;
__int128 q;
__int128 op, c, x, k;
deque<pair<__int128, __int128>> a;
istream& operator>>(istream& is, __int128& x) {
  int a = 0;
  is >> a;
  x = a;
  return is;
}
ostream& operator<<(ostream& os, __int128 x) {
  if (x == 0) return os << 0;
  stack<int> s;
  while (x != 0) {
    s.push(x % 10);
    x /= 10;
  }
  while (!s.empty()) os << s.top(), s.pop();
  return os;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> q;
  while ((q--) != 0) {
    cin >> op;
    if (op == 1) {
      cin >> c >> x;
      a.emplace_back(x, c);
    } else {
      cin >> k;
      __int128 sum = 0;
      while (!a.empty() && a.front().second <= k) {
        sum += a.front().first * a.front().second;
        k -= a.front().second;
        a.pop_front();
      }
      if (k > 0 && !a.empty()) {
        sum += a.front().first * k;
        a.front().second -= k;
        k = 0;
      }
      cout << sum << endl;
    }
  }
  return 0;
}
