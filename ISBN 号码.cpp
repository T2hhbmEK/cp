#include <bits/stdc++.h>
using namespace std;
string s;
int hs, cnt;
int main() {
    cin >> s;
    int sz = s.size();
    for (int i = 0; i < sz - 1; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            cnt += 1;
            hs += (s[i] - '0') * cnt;
            hs %= 11;
        }
    }
    char c = '0' + hs;
    if (hs == 10) c = 'X';
    if (c == s[sz - 1]) {
        cout << "Right";
    } else {
        s[sz - 1] = c;
        cout << s;
    }
    return 0;
}