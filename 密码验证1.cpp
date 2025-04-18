#include <bits/stdc++.h>
using namespace std;
string s[15];
int main() {
    for (int i = 1; i <= 11; ++i) {
        cin >> s[i];
    }
    for (int i = 1; i <= 10; ++i) {
        if (s[i] == s[11]) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}