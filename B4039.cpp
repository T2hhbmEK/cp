#include <bits/stdc++.h>
using namespace std;

bool is_hw(string& s, int a, int b) {
    for (int i = a, j = b - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return false;
    }
    return true;
}

bool check(string& s) {
    int len = s.size();
    for (int i = 2; i <= len - 2; i++) {
        if (is_hw(s, 0, i) && is_hw(s, i, len)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        if (check(s)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
