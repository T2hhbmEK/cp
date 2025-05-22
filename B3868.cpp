#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        //            2  8  10 16
        int ans[4] = {1, 1, 1, 1};
        for (int j = 0; j < (int)s.size(); j++) {
            char ch = s[j];
            if (isdigit(ch)) {
                int x = ch - '0';
                if (x >= 2) ans[0] = 0;
                if (x >= 8) ans[1] = 0;
            } else {
                ans[0] = ans[1] = ans[2] = 0;
                if (ch > 'F') ans[3] = 0;
            }
        }
        for (int j = 0; j < 4; j++) {
            cout << ans[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
