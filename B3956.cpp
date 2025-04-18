#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (islower(ch)) {
            ans += ch - 'a' + 1;
        } else {
            ans -= ch;
        }
    }
    cout << ans;
    return 0;
}
