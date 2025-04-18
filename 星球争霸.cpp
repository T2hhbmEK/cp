#include <bits/stdc++.h>
using namespace std;
int n;
string s, yyzm = "AEIOUaeiou";
void f(string &s) {
    char c = s[s.size() - 1];
    for (int i = 0; i < yyzm.size(); ++i) {
        if (c == yyzm[i]) {
            cout << "William" << endl;
            return;
        }
    }
    if (c == 'y' || c == 'Y') {
        cout << "No" << endl;
        return;
    }
    cout << "John" << endl;
}
int main() {
    cin >> n;
    while (n--) {
        cin >> s;
        f(s);
    }
    return 0;
}