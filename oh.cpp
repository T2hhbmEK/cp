#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int cnt = 1;
int main() {
    cin >> s;
    for (int i = 0; s[i]; i++) {
        cout << s[i];
        if (s[i] == 'o') {
            for (int j = 1; j <= cnt; j++) {
                cout << 'h';
            }
            cnt += 1;
        }
    }
    return 0;
}
