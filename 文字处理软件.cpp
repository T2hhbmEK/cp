#include <bits/stdc++.h>
using namespace std;
int q, op, a, b;
string s, t;
int main() {
    cin >> q >> s;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> t;
            s += t;
            cout << s << endl;
        } else if (op == 2) {
            cin >> a >> b;
            s = s.substr(a, b);
            cout << s << endl;
        } else if (op == 3) {
            cin >> a >> t;
            s = s.substr(0, a) + t + s.substr(a);
            cout << s << endl;
        } else if (op == 4) {
            cin >> t;
            size_t p = s.find(t);
            if (p == string::npos) {
                cout << -1 << endl;
            } else {
                cout << p << endl;
            }
        }
    }
    return 0;
}