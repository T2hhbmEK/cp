#include <iostream>
#include <string>
using namespace std;

int main() {
  int q, op, a, b, p;
  string s, t;
  cin >> q >> s;
  while (q--) {
    cin >> op;
    switch (op) {
      case 1:
        cin >> t;
        s += t;
        cout << s << endl;
        break;
      case 2:
        cin >> a >> b;
        s = s.substr(a, b);
        cout << s << endl;
        break;
      case 3:
        cin >> a >> t;
        s.insert(a, t);
        cout << s << endl;
        break;
      case 4:
        cin >> t;
        p = s.find(t);
        cout << p << endl;
        break;
      default:
        break;
    }
  }
  return 0;
}
