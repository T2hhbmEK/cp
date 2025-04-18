#include <bits/stdc++.h>
using namespace std;
string s, d = "VWXYZABCDEFGHIJKLMNOPQRSTU";
int main() {
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = d[s[i] - 'A'];
        }
    }
    cout << s;
    return 0;
}