#include <bits/stdc++.h>
using namespace std;
string s, t;
int n, sz, tj;
int main() {
    cin >> s >> n;
    while (n--) {
        cin >> t;
        if (t.size() != s.size()) continue;
        int xt = 1;
        for (int i = 0; i <= s.size(); ++i) {
            if (s[i] == '#') continue;
            if (s[i] != t[i]) {
                xt = 0;
                break;
            }
        }
        if (xt) tj += 1;
    }
    cout << tj;
    return 0;
}