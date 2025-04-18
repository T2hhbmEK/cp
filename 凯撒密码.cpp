#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[256];
char rot(char c, int d) {
    c += d;
    while (c > 'Z') {
        c -= 26;
    }
    while (c < 'A') {
        c += 26;
    }
    return c;
}
int main() {
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i) {
        cnt[s[i]] += 1;
    }
    char c = 'A';
    for (int i = 'A'; i <= 'Z'; ++i) {
        if (cnt[i] > cnt[c]) {
            c = i;
        }
    }
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = rot(s[i], 'E' - c);
        }
    }
    cout << s;
    return 0;
}