#include <bits/stdc++.h>
using namespace std;
int n;
string s;
char uppercase(char c) {
    if (c >= 'a' && c <= 'z') {
        c += 'A' - 'a';
    }
    return c;
}
char lowercase(char c) {
    if (c >= 'A' && c <= 'Z') {
        c += 'a' - 'A';
    }
    return c;
}
int main() {
    cin >> n;
    while (n--) {
        cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            s[i] = lowercase(s[i]);
        }
        s[0] = uppercase(s[0]);
        cout << s << endl;
    }
    return 0;
}