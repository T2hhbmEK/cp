#include <bits/stdc++.h>
using namespace std;

int readint(string& s, int& i) {
    int x = 0;
    while (isdigit(s[i])) x = x * 10 + (s[i++] - '0');
    return x;
}

string f(string& s, int& i) {
    string res;
    while (s[i]) {
        char ch = s[i++];
        if (ch == '[') {
            int n = readint(s, i);
            string t = f(s, i);
            while (n--) res += t;
        } else if (ch == ']') {
            return res;
        } else {
            res += ch;
        }
    }
    return res;
}

int main() {
    string s;
    int i = 0;
    cin >> s;
    cout << f(s, i) << endl;
    return 0;
}
