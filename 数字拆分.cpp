#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

int k, cnt;

bool check(int x) {
    for (int i = 1; i <= 3; i++) {
        if (x % 1000 % k != 0) {
            return 0;
        }
        x /= 10;
    }
    return 1;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> k;

    for (int i = 10000; i <= 30000; ++i) {
        if (check(i)) {
            cout << i << endl;
            ++cnt;
        }
    }
    if (cnt == 0) {
        cout << "No";
    }
    return 0;
}
