#include <bits/stdc++.h>
using namespace std;

string s, t;
int n;

int main() {
    cin >> s >> n;
    while (n--) {
        t = "";
        for (int i = 0; s[i]; ++i) {
            if (s[i] == '0') {
                t += "1";
            } else {
                t += "01";
            }
        }
        s = t;
    }
    cout << s;
    return 0;
}
