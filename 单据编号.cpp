#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            int a = i * 10000 + j * 10 + 1708;
            if (a % 7 == 0 || a % 11 == 0) {
                cout << a << endl;
            }
        }
    }
    return 0;
}
