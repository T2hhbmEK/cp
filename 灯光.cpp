#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int L, R;
    cin >> L >> R;
    for (int i = 1; 3 * i * i < R; i++) {
        for (int j = 1; 3 * i * i + 3 * j * j <= R; j++) {
            if (3 * i * i + 3 * j * j >= L) {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}
