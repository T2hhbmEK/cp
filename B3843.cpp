#include <bits/stdc++.h>
using namespace std;

bool check(string& s) {
    int n = s.size();
    int cntA = 0, cnta = 0, cnt0 = 0, cnt_ = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') {
            cntA++;
        } else if (c >= 'a' && c <= 'z') {
            cnta++;
        } else if (c >= '0' && c <= '9') {
            cnt0++;
        } else if (c == '!' || c == '@' || c == '#' || c == '$') {
            cnt_++;
        } else {
            return false;
        }
    }
    if (n < 6 || n > 12) return false;
    if (cnt_ == 0) return false;
    int cnt = 0;
    if (cntA > 0) cnt++;
    if (cnta > 0) cnt++;
    if (cnt0 > 0) cnt++;
    if (cnt < 2) return false;
    return true;
}

int main() {
    string s, t;
    cin >> s;
    for (int i = 0; i <= (int)s.size(); i++) {
        char c = s[i];
        if (c == '\0' || c == ',') {
            if (check(t)) cout << t << '\n';
            t = "";
        } else {
            t += c;
            // cout << t << endl;
        }
    }
    return 0;
}
